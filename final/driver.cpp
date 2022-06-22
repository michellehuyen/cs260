#include "graph.h"

using std::cin;

void choiceCheck(int &c);
void numCheck(int &n);
void src_destCheck(int &s, int &d);

void choiceCheck(int &c) {
    while (c != 1 && c != 2 && c != 3 && c!= 4 && c != 5) {
        cout << endl;
        cout << "Please enter a valid number !" << endl;
        cout << "Enter 1 to add a vertex" << endl;
        cout << "Enter 2 to add a new edge" << endl;
        cout << "Enter 3 for the shortest path algorithm" << endl;
        cout << "Enter 4 for the minimum spanning tree" << endl;
        cout << "Enter 5 to quit" << endl;
        cout << "Enter a number (1-5): ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> c;
        }
    }
}

void numCheck(int &n) {
    while (cin.fail()) {
        cout << endl;
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Please enter a number !" << endl;
        cout << "Enter a number: ";
        cin >> n;
        cout << endl;
    }
}

void src_destCheck(int &s, int &d) {
    while (s == d) {
        cout << endl;
        cout << "You cannot enter the same number twice !" << endl;
        cout << "Enter the number for the source: ";
        cin >> s;
        numCheck(s);
        
        cout << "Enter the number for the destination: ";
        cin >> d;
        numCheck(d);
    }
}

int main() {
    Graph g;
    int choice = 0, vertex = 0, source = 0, destination = 0;

    do {
        cout << endl;
        cout << "Enter 1 to add a vertex" << endl;
        cout << "Enter 2 to add a new edge" << endl;
        cout << "Enter 3 for the shortest path algorithm" << endl;
        cout << "Enter 4 for the minimum spanning tree" << endl;
        cout << "Enter 5 to quit" << endl;
        cout << "Enter a number (1-5): ";
        cin >> choice;
        choiceCheck(choice);

        if (choice == 1) {
            cout << endl;
            cout << "Enter a number for the vertex: ";
            cin >> vertex;

            numCheck(vertex);
            g.addVertex(vertex);
        }
        else if (choice == 2) {
            cout << endl;
            cout << "Enter the number for the source vertex: ";
            cin >> source;
            numCheck(source);

            cout << "Enter the number for the destination vertex: ";
            cin >> destination;
            numCheck(destination);
            src_destCheck(source, destination);

            cout << endl;
            g.addEdge(source, destination);
        }
        else if (choice == 3) {
            cout << endl;
            cout << "Enter the number for the source vertex: ";
            cin >> source;
            numCheck(source);

            cout << "Enter the number for the destination vertex: ";
            cin >> destination;
            numCheck(destination);

            src_destCheck(source, destination);
            cout << endl;
            g.shortestPath(source, destination);
        }
        else if (choice == 4) {
            cout << endl;
            cout << "min span tree goes here !" << endl;
            // g.minSpanTree();
        }
        g.printGraph();

        cout << endl;

    } while (choice != 5);

    cout << endl;

    return 0;
}