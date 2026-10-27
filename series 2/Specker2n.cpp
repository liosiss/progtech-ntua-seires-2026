#include "Specker1n.cpp"
#include <iostream>
#include <string>
using namespace std;

class Player{
    public:
    Player(const string &n){
        name=n;
    }
    virtual ~Player(){
        name.clear();
    }
    virtual const string & getType() const=0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (std::ostream &out, const Player &player){
        out << player.getType() << " player " << player.name;
        return out;
    }

    private:
    string name;
};

class player_Greedy: public Player{
    public:
    player_Greedy(const string &n):Player(n){
        type="Greedy";
    }

    virtual const string &getType() const{
        return type;
    }


    virtual Move play(const State &s){
        int max=0;
        for(int i=1; i<s.getHeaps(); i++)
            if(s.getCoins(i)>s.getCoins(max)) max=i;
        return Move(max, s.getCoins(max), 0, 0);
    }

    private:
    string type;
};


class player_Spartan: public Player{
    public:
    player_Spartan(const string &n): Player(n){
        type="Spartan";
    }

    virtual const string &getType() const{
        return type;
    }

    virtual Move play(const State &s){
        int max=0;
        for(int i=1; i<s.getHeaps(); i++)
            if(s.getCoins(i)>s.getCoins(max)) max=i;
        return Move(max, 1, 0, 0);
    }
    private:
    string type;
};

class player_Sneaky: public Player{
    public:
    player_Sneaky(const string &n):Player(n){
        type="Sneaky";
    }

    virtual const string &getType() const{
        return type;
    }

    virtual Move play(const State &s){
        int min=0;
        for(int i=0; i<s.getHeaps(); i++){
            if(s.getCoins(min)>s.getCoins(i)) min=i;
        }
        return Move (min, s.getCoins(min), 0, 0);
    }
        private:
        string type;
};

    class player_Righteous: public Player{
        public:
        player_Righteous(const string &n):Player(n){
            type="Righteous";
        }

        virtual const string &getType() const{
            return type;
        }

        virtual Move play(const State &s){
            int min=0;
            for(int i=0; i<s.getHeaps(); i++)
               if(s.getCoins(min)>s.getCoins(i)) min=i;
            int max=0;
            for(int i=1; i<s.getHeaps(); i++)
               if(s.getCoins(i)>s.getCoins(max)) max=i;
            return Move (max, s.getCoins(max)/2, min, s.getCoins(max)/2-1);
        }
        
        private:
        string type;
    };

 



