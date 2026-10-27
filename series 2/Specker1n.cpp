#include <iostream>
#include <stdexcept>
using namespace std;

class Move {
    public:
    Move(int sh, int sc, int th, int tc);

    int getSource() const;
    int getSourceCoins() const;
    int getTarget() const;
    int getTargetCoins() const;

    friend ostream & operator << (ostream &out, const Move &move);
    
    private:
    int source, source_coins, target, target_coins;
};

Move::Move(int sh, int sc, int th, int tc){
    source=sh;
    source_coins=sc;
    target=th;
    target_coins=tc;
}

int Move::getSource() const {
    return source;
}

int Move::getSourceCoins() const{
    return source_coins;
}

int Move::getTarget() const{
    return target;
}

int Move::getTargetCoins() const{
    return target_coins;
}

ostream & operator << (ostream &out, const Move &move){
    if(move.target_coins!=0){
        out << "take " << move.source_coins << " coins from heap " << move.source << " and puts " << move.target_coins << " coins to heap " << move.target;
        return out; 
    }
    else {
          out << "take " << move.source_coins << " coins from heap " << move.source << " and puts nothing";
    }
}




class State {
    public:
    State(int h, const int c[], int n);
    ~State();

    void next(const Move &move) throw (logic_error); 
    bool winning() const;

    int getHeaps() const;
    int getCoins(int h) const throw (logic_error); 

    int getPlayers() const;
    int getPlaying() const;

    friend ostream & operator << (ostream &out, const State &state);

    private:
    int heaps, players_num, now;
    int *heap_coins;
};

State::State(int h, const int c[], int n){
    heaps=h;
    players_num=n;
    heap_coins =new int [heaps];
    for(int i=0; i<heaps; i++){
        heap_coins[i]=c[i];
    }
    now=0;
}

State::~State(){   
    delete [] heap_coins;
}

void State::next(const Move &move) throw (logic_error){
    if(move.getSource()>=heaps || move.getSource()<0 || move.getTarget()>=heaps || move.getTarget()<0 || move.getSourceCoins()<1 || move.getSourceCoins()<getCoins(move.getSource()) || move.getTargetCoins() >= move.getSourceCoins() ){
        throw logic_error("invalid move");
    }
    else{
        heap_coins[move.getSource()] -= move.getSourceCoins();
        heap_coins[move.getTarget()] += move.getTargetCoins();
    }
    if(now==players_num-1) now=0;
    else now++;
}


bool State::winning() const{
    bool end=true;
    for(int i=0; i<heaps; i++) 
        if (heap_coins[i]!=0){
            end=false;
            break;
        }
    return end;
}

int State::getHeaps() const{
    return heaps;
}

int State::getPlayers() const{
    return players_num;
}

int State::getPlaying() const{
    return now;
}

int State::getCoins(int h) const throw (logic_error){
    if (h<0 || h>=heaps) throw logic_error("invalid move");
    else return heap_coins[h]; 
}

std::ostream & operator << (std::ostream &out, const State &state){
    for(int i=0; i<state.heaps-1; i++ ) out << state.heap_coins[i] << ", ";
    out << state.heap_coins[state.heaps-1] << " with " << state.now << "/" << state.players_num << " playing next";
    return out;
}

