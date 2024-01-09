#include <iostream>
#include <string>
#include <vector>
#include <queue>
/**
 * Route Between Nodes:
 *  
 * Given a directed graph and two nodes (S and E), 
 * design an algorithm to find out whethere there is a route from S to E.
 * 
*/


class Node {
    public:
        std::string name;
        int marked;
        std::vector<Node*> children;
       

        // Constructor
        Node(std::string n) : name(n), marked(0) {}

        void add_node(Node* child) {
            children.push_back(child);
        }

};


class Graph {
    public:
        std::vector<Node*> nodes;
        
        void add_node(std::string node_name) {
            Node* new_node = new Node(node_name);
            nodes.push_back(new_node);
        }

        Node* get_node(std::string node_name) {
            for (auto n : nodes) {
                if (n->name == node_name) {
                    return n;
                }
            }
            return nullptr;
        }

        bool search(Node* root, Node* end) {
            if (root == end) return true;

            std::queue<Node*> q;

            for (auto n : nodes) {
                n->marked = 0;
            }

            root->marked = 1;
            q.push(root);

            while(!q.empty()) {
                Node* r = q.front();
                q.pop();

                for (auto child : r->children) {
                    if (!child->marked) {
                        if(child == end) {
                            std::cout << "Target Found: There is a Route" << std::endl;
                            return true;
                        } else {
                            child->marked = 1;
                            q.push(child);
                        }
                    }
                }
            }
            return false;
        }

        ~Graph() {
            for (auto node : nodes) {
                delete node;
            }
        }

};


int main() {

    Graph my_graph;

    my_graph.add_node("A");
    my_graph.add_node("F");
    my_graph.add_node("D");
    my_graph.add_node("S");
    my_graph.add_node("B");
    my_graph.add_node("G");
    my_graph.add_node("P");
    my_graph.add_node("E");

    Node* A = my_graph.get_node("A");
    Node* F = my_graph.get_node("F");
    Node* D = my_graph.get_node("D");
    Node* S = my_graph.get_node("S");
    Node* B = my_graph.get_node("B");
    Node* G = my_graph.get_node("G");
    Node* E = my_graph.get_node("E");
    Node* P = my_graph.get_node("P");

    A->add_node(B);
    A->add_node(F);
    F->add_node(G);
    B->add_node(E);
    F->add_node(S);
    F->add_node(D);
    S->add_node(D);
    D->add_node(P);
    D->add_node(B);


    std::cout << "Nodes in the graph:" << std::endl;
    for (auto n : my_graph.nodes) {
        std::cout << n->name << std::endl;
    }

    bool route_exists = my_graph.search(S, E);
    std::cout << "Route exist: " << (route_exists ? "Yes" : "No") << std::endl;
    return 0;

}