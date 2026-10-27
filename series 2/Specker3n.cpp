#include "Specker1n.cpp"
#include "Specker2n.cpp"
#include <iostream>
#include <string>
using namespace std;


class Game: public State{
    public:
    Game(int heaps, int players){
        maxh=heaps;
        maxp=players;
        pcount=hcount=0;
        a=new int [heaps];
        p=new  Player *[players];
    }

    ~Game(){
        delete [] a;
        delete [] p;
    }

    void addHeap(int coins) throw(logic_error){
        if(coins<0) throw logic_error("Dwse thetiko arithmo");
        else if (hcount>=maxh) throw logic_error("Gemises oles tis swrous");
        else{
            a[hcount++]=coins;
        }
    }

    void addPlayer(Player *player){
        if(pcount>=maxp) throw logic_error("Den xwrane alloi paiktes");
        else{
            p[pcount++]=player;
        }
    }


    void play(std::ostream &out) throw(logic_error){
        if(hcount!=maxh || pcount!=maxp) throw logic_error("Dwse kai allous paiktes kai swrous");
        else{
            State s(maxh, a[], maxp);
            while(s.winning()!=){
                out << "State: " << s << endl;
                out << *getPlayer(s.getPlaying()) << " " << p[s.getPlaying()]->play(s) <<endl;
                s.next(p[s.getPlaying()]->play(s));
            }

            out <<"State: " << s << endl;
            if (s.getPlaying()==0){
                 out << *p[maxp-1] << " wins" << endl;
            }
            else{
                out << *p[s.getPlaying()-1] << " wins" << endl;
            }
        }
    }

    int getPlayers() const{
        return maxp;
    }
    
    const Player *getPlayer(int n) const throw(logic_error){
        if(n>=maxp || n<0) throw logic_error("error");
        else {
            return p[n];
        }
    }

    private: 
    int maxh, maxp;
    int *a; //heap array
    Player  **p; //players array
    int pcount, hcount;
};
