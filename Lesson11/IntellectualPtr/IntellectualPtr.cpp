#include <iostream>
#include <vector>
#include <algorithm> // для for_each
#include <memory> // для std::shared_ptr
using namespace std;

class Song {
    string _song;
    string _base64Photo;
    weak_ptr<Song> album; // Если заменить на shared_ptr (Будет один деструктор!)
public:
    Song() : _song{ "" } {}
    Song(string song, string base64Photo) : _song{ song }, _base64Photo{ base64Photo } {}
    ~Song() { cout << "Destroyed:\t" << typeid(this).name() << "\t" << this << endl; }
    friend ostream& operator<< (ostream& out, const Song& song)
    {
        out << song._song << "\n" << song._base64Photo << endl;
        return out;
    }
    friend void CreateAlbum(shared_ptr<Song>& a, shared_ptr<Song>& b, shared_ptr<Song>& c)
    {
        // Циклическая зависимость
        a->album = b;
        b->album = a;
        c->album = a;
    }
};

int main()
{
    shared_ptr<Song> a = make_shared<Song>("aSong", "aPhoto");
    shared_ptr<Song> b = make_shared<Song>("bSong", "bPhoto");
    shared_ptr<Song> c = make_shared<Song>("cSong", "cPhoto");

    CreateAlbum(a, b, c); // Циклическая связь

    vector<shared_ptr<Song>> songs;
    songs.push_back(a);
    songs.push_back(b);
    songs.push_back(c);

    for_each(songs.begin(), songs.end(), [](shared_ptr<Song> wp) { 
        cout << *wp << endl;
    });
}
