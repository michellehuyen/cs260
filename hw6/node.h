using std::cout;
using std::endl;
using std::cin;
using std::string;

class Node {
    private:
        int val;
        int left;
        int right;
        Node *next;
    public:
        Node();
        
        int get_val() const;
        int get_left() const;
        int get_right() const;
        Node *get_next() const;

        void set_val(int);
        void set_left(int);
        void set_right(int);
        void set_next(Node*);
};