#include <iostream>
#include <string>

class Data_Package {
public:
    int key;
    std::string description;
    static int num_pkg;
    
    Data_Package(std::string description) {
        Data_Package::num_pkg++;
        this->key = Data_Package::num_pkg;
        this->description = description;
    }
    
    void print() {
        std::cout << "key: " << key << "\t" << description << std::endl;
    }
};

struct Node {
    Node* left;
    Data_Package* data;
    Node* right;
};

class Binary_Tree {
    int size;

public:
    Node* root;

    Binary_Tree() {
        size = 0;
        root = nullptr;
    }

    ~Binary_Tree() {
        // Destructor implementation if needed
        delete_branch(root);
    }

    void delete_branch(Node* node) {
        if (node == nullptr)
            return;
        delete_branch(node->left);
        delete_branch(node->right);
        delete node->data;
        delete node;
    }

    Data_Package* find(int the_key, Node* branch) {
        Node * current_node = branch;
        if (current_node != nullptr)
            if (current_node->data->key==the_key)
                return current_node->data;
            else {
                find(the_key,current_node->left);
                find(the_key,current_node->right);
            }
        return nullptr;
    }

    int remove(int the_key) {
        // Implement remove function
        return -1; // Placeholder return statement
    }

    int insert(Data_Package* the_data) {
        this->size++;
        Node* new_node = new Node;
        new_node->data = the_data;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (this->root == nullptr) {
            this->root = new_node;
            return 0;
        } else {
            Node* current = this->root;
            Node* parent = nullptr;

            while (current != nullptr) {
                parent = current;

                if (the_data->key < current->data->key)
                    current = current->left;
                else if (the_data->key > current->data->key)
                    current = current->right;
                else
                    return -1; // Duplicate keys not allowed
            }
            if (the_data->key < parent->data->key)
                parent->left = new_node;
            else
                parent->right = new_node;
        }
        return 0;
    }

    int get_height(Node* node) {
        if (node == nullptr)
            return 0;
        else
            return std::max(get_height(node->left), get_height(node->right)) + 1;
    }

    int get_size(Node* node) {
        if (node == nullptr)
            return 0;
        else
            return get_size(node->left) + get_size(node->right) + 1;
    }

    void print_tree_ascii(Node* node, int level) {
        if (node == nullptr) {
            return;
        }

        std::string indent = string(level * 2, ' ');
        std::cout << indent << node->data->key << std::endl;

        print_tree_ascii(node->left, level + 1);
        print_tree_ascii(node->right, level + 1);
    }

    std::string print_tree_mermaid(Node* node, int level) {
        if (node == nullptr) {
            return "";
        }

        std::string indent = std::string(level * 2, ' ');
        std::string s = indent + "node " + std::to_string(node->data->key) + " [" +
                  "label=\"" + node->data->key + "\"];\n";

        s += print_tree_mermaid(node->left, level + 1);
        s += print_tree_mermaid(node->right, level + 1);

        return s;
    }
};

std::string print_tree_mermaid(Node* node, int level) {
    if (node == nullptr) {
        return "";
    }

    std::string indent = std::string(level * 2, ' ');
    std::string s = indent + "node " + std::to_string(node->data->key) + " [" +
                  "label=\"" + node->data->key + "\"];\n";

    s += print_tree_mermaid(node->left, level + 1);
    s += print_tree_mermaid(node->right, level + 1);

    return s;
}

int Binary_Tree::remove(int the_key) {
    // Find the node to be removed
    Node* current = this->root;
    Node* parent = nullptr;

    while (current != nullptr && current->data->key != the_key) {
        parent = current;

        if (the_key < current->data->key)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr)
        return -1; // Key not found

    // Case 1: The node to be removed has no children
    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr) {
            this->root = nullptr;
        } else {
            if (the_key < parent->data->key)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
    }

    // Case 2: The node to be removed has one child
    else if (current->left == nullptr || current->right == nullptr) {
        Node* child = current->left;
        if (child == nullptr)
            child = current->right;

        if (parent == nullptr) {
            this->root = child;
        } else {
            if (the_key < parent->data->key)
                parent->left = child;
            else
                parent->right = child;
        }
    }

    // Case 3: The node to be removed has two children
    else {
        Node* successor = current->right;
        Node* successor_parent = current;

        while (successor->left != nullptr) {
            successor_parent = successor;
            successor = successor->left;
        }

        // Replace the data of the node to be removed with the data of the successor
        current->data = successor->data;

        // Remove the successor node
        if (successor_parent == current) {
            current->right = successor->right;
        } else {
            successor_parent->left = successor->right;
        }
    }

    this->size--;
    return 0;
}

int main() {
    Binary_Tree my_tree;
    Data_Package my_data1("Primeiro pacote de dados");
    my_tree.insert(&my_data1);
    Data_Package my_data2("Segundo pacote de dados");
    my_tree.insert(&my_data2);
    Data_Package my_data3("Terceiro pacote de dados");
    my_tree.insert(&my_data3);
    Data_Package my_data4("Quarto pacote de dados");
    my_tree.insert(&my_data4);
    Data_Package my_data5("Quinto pacote de dados");
    my_tree.insert(&my_data5);
    Data_Package my_data6("Sexto pacote de dados");
    my_tree.insert(&my_data6);
    Data_Package my_data7("Sétimo pacote de dados");
    my_tree.insert(&my_data7);
    Data_Package my_data8("Oitavo pacote de dados");
    my_tree.insert(&my_data8);
    Data_Package my_data9("Nono pacote de dados");
    my_tree.insert(&my_data9);

    std::cout << "Height of tree: " << my_tree.get_height(my_tree.root) << std::endl;
    std::cout << "Size of tree: " << my_tree.get_size(my_tree.root) << std::endl;

    return 0;
}





