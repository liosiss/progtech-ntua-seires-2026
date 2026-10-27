#include <iostream>
#include <string>
using namespace std;

class lexicon{
public:

    lexicon() : root(nullptr) {};
    
    ~lexicon(){
       clear(root);
    };

    void insert (const string &s) {
        doinsert(s);
    };

    int lookup (const string &s) const {
        return dolookup(s);
    };

    int depth (const string &s) {
        return finddepth(s);
    };

    void replace (const string &s1, const string &s2) {
        doreplace(s1, s2);
    };

    friend ostream &operator << (ostream &out, const lexicon &l) {
        l.printinorder(l.root);
        out <<"";
        return  out;
    }

private:
          
    struct node {
        string word;
        int frequence;
        node *left, *right;

        node (const string &w, int k = 1, node *child1 = nullptr, node *child2 = nullptr) : word (w), frequence(k), left(child1), right(child2) {}; 
    };

    node *root;

    void clear(node *p){
    if (p == nullptr) return;
    clear(p->left);
    clear(p->right);
    delete p;
    }

    void doinsert(const string &s, int k=1){
        if (root == nullptr) {
            root = new node(s, k);
            return;
        }

        node *a = root;
        node *parent = nullptr;
        while (a != nullptr){
            parent = a;
            if (a->word == s ) {
                a->frequence += k;
                return;
            }
            else if (a->word > s) a = a->left; 
            else if (a->word < s) a = a->right;
        }
        
        if (s < parent->word) parent->left = new node (s, k);
        else parent->right = new node (s, k);
        return;
    }

    int dolookup (const string &s) const{
        node *a = root;
        int f = 0;
         while (a != nullptr){
            if (a->word == s ) {
                return a->frequence;
            }
            else if (a->word > s)  a = a->left;
            else if (a->word < s) a = a->right;
        }
        return f;
    }  

    int finddepth (const string &s) {
        node *a = root;
        int count = 0;
        while (a != nullptr){
            if (a->word == s ) {
                return count;
            }
            else if (a->word > s) {
                a = a->left;
                count++;
            }
            else if (a->word < s) {
                count++;
                a = a->right;
            }
        }
        if (count == 0) return -1;
        return count;
    }



    node* delete_node(node *q, string s) {
    if (q == nullptr) return q;

    if (s < q->word) {
        q->left = delete_node(q->left, s);
    }
    else if (s > q->word) {
        q->right = delete_node(q->right, s);
    }
    else {
        if (q->left == nullptr && q->right == nullptr) {
            delete q;
            return nullptr;
        }
        else if (q->left == nullptr) {
            node *t = q->right;
            delete q;
            return t;
        }
        else if (q->right == nullptr) {
            node *t = q->left;
            delete q;
            return t;
        }

        node *t = min_value(q->right);
        q->word = t->word;
        q->frequence = t->frequence;
        q->right = delete_node(q->right, t->word);
    }

    return q;
    }  

    node *min_value (node *q){
        while (q->left != nullptr){
            q = q->left;
        }
        return q;
     }


    
    void doreplace (const string &s1, const string &s2) {
        int frequence_s1 = dolookup(s1);
        if (frequence_s1 == 0) return;
        root = delete_node(root, s1); 
        doinsert (s2, frequence_s1);
    }

    void printinorder (const node *p) const{
        if (p == nullptr ) return;
        printinorder (p->left);
        cout << p->word << " " << p->frequence << endl;
        printinorder (p->right);
        return;
    }
};


int main () {
    lexicon l;
 l.insert("the");
 l.insert("boy");
 l.insert("and");
 l.insert("the");
 l.insert("wolf");
 cout << "The word ’the’ is found " << l.lookup("the") << " time(s)" << endl;
 cout << "The word ’and’ is found at depth " << l.depth("and") << endl;
 cout << l;
 l.replace("boy", "wolf");
 cout << "After replacement:\n";
 cout << l;
 cout << "Now the word ’and’ is found at depth " << l.depth("and") << endl;
 return 0;
}