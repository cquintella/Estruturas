#include <iostream>
#include <string>

// Nosso tipo de dado composto. É isso que vamos guardar na árvore.
class Data_Package {
public:
    int key;                        // Um tipo com chave e descrição.
    std::string description;    
    static int num_pkg;             // Isso aqui é estático serve pra contar o numero de pacotes para gerar numero sequencial da chave.
    
    Data_Package(std::string description) {            // Aqui é o construtor
        Data_Package::num_pkg++;                       // A chave cresce sequencialmente.
        this->key = Data_Package::num_pkg;
        this->description = description;
    }
    
    void print() {                                     // Um método que imprime o item de dados.
        std::cout << "key: " << key << "\t" << description << std::endl;
    }
};

                      

struct Node {
    Node* left;
    Data_Package* data;
    Node* right;
};

class Binary_Tree {                      // Nossa classe de árvore binária
    int size;                            // contador de número de nós
    
public: 
    Node* root;                          // Ela tem uma raiz
    
    Binary_Tree() {
        size = 0;
        root = nullptr;
    }
    
    ~Binary_Tree() {
        // Destructor implementation if needed
        delete_tree(root);
    }
    
    void delete_tree(Node* node) {          // Usamos pós ordem para excluir os nós da árvore
        if (node == nullptr)                // se não tem nada para excluir retorna.
            return;
        
        delete_tree(node->left);           // apagar à esqueda, se tiver.
        delete_tree(node->right);          // apagar componentes à direita, se tiver.
        std::cout<<"Deleting Node: "<<node<<std::endl;
        delete node->data;                // excluir o dado dessa folha.
        this->size--;                      // diminuir o tamanho da árvore.
        delete node;                      // tirar a folha.
    }
    
Node* find(int the_key) {
    Node* current = this->root;
    while (current != nullptr) {
        if (the_key == current->data->key) {
            return current;
        } else if (the_key < current->data->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr; // Item não encontrado na árvore
}


Node* get_parent(Node* current, Node* node) {
    if (current == nullptr || current == node) {
        return nullptr; // Não há pai ou o nó atual é o nó procurado
    }

    if (current->left == node || current->right == node) {
        return current; // Encontrou o pai do nó
    }

    Node* parent = get_parent(current->left, node);
    if (parent != nullptr) {
        return parent; // O pai foi encontrado na subárvore esquerda
    }

    return get_parent(current->right, node); // Procurar na subárvore direita
}

    
int remove(Node* node_to_remove) {
    if (node_to_remove == nullptr) {
        return -1; // Nó não encontrado na árvore
    }

    Node* parent = get_parent(root, node_to_remove);
    bool is_left_child = (parent != nullptr && parent->left == node_to_remove);

    // Caso 1: Nó a ser removido é uma folha (não tem filhos)
    if (node_to_remove->left == nullptr && node_to_remove->right == nullptr) {
        if (parent == nullptr) {
            root = nullptr; // Nó a ser removido é a raiz
        } else if (is_left_child) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }
    // Caso 2: Nó a ser removido tem apenas um filho
    else if (node_to_remove->left == nullptr) {
        Node* child = node_to_remove->right;
        if (parent == nullptr) {
            root = child; // Nó a ser removido é a raiz
        } else if (is_left_child) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    } else if (node_to_remove->right == nullptr) {
        Node* child = node_to_remove->left;
        if (parent == nullptr) {
            root = child; // Nó a ser removido é a raiz
        } else if (is_left_child) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
    // Caso 3: Nó a ser removido tem dois filhos
    else {
        Node* successor_parent = node_to_remove;
        Node* successor = node_to_remove->right;

        while (successor->left != nullptr) {
            successor_parent = successor;
            successor = successor->left;
        }

        if (successor_parent != node_to_remove) {
            successor_parent->left = successor->right;
            successor->right = node_to_remove->right;
        }

        successor->left = node_to_remove->left;

        if (parent == nullptr) {
            root = successor; // Nó a ser removido é a raiz
        } else if (is_left_child) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }
    }

    delete node_to_remove;
    size--;
    return 0; // Remoção bem-sucedida
}

std::string show_branch(Node* branch_root) {
    std::string diagram = "";

    if (branch_root != nullptr) {
        std::string current_node = "Node" + std::to_string(branch_root->data->key);
        diagram += current_node + "[" + std::to_string(branch_root->data->key) + "]\n";

        if (branch_root->left != nullptr) {
            std::string left_node = show_branch(branch_root->left);
            diagram += current_node + "-->|Esq|" + left_node + "\n";
        }

        if (branch_root->right != nullptr) {
            std::string right_node = show_branch(branch_root->right);
            diagram += current_node + "-->|Dir|" + right_node + "\n";
        }
    }

    return diagram;
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

    void in_order_traversal(Node* node) {
        if (node == nullptr) {
                return;
        }
        
        in_order_traversal(node->left);
        node->data->print();
        in_order_traversal(node->right);
    }
    
    void post_order_traversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        node->data->print();
    }
    
    void pre_order_traversal(Node* node) {
        if (node == nullptr) {
            return;
        }
    
        node->data->print();
        pre_order_traversal(node->left);
        pre_order_traversal(node->right);
    }
};

int Data_Package::num_pkg = 0;  

int main() {

// Criando elementos
    Data_Package my_data1("Raul");
    Data_Package my_data2("Leandro");
    Data_Package my_data3("Junior");
    Data_Package my_data4("Rondinelli");
    Data_Package my_data5("Carpegiani");
    Data_Package my_data6("Tita");
    Data_Package my_data7("Nunes");
    Data_Package my_data8("Andrade");
    Data_Package my_data9("Zico");    
    Data_Package my_data10("Fumanchu");    
    Data_Package my_data11("Nei Dias");
    Data_Package my_data12("Carlos Alberto");
    Data_Package my_data13("Luiz Alberto");    
    Data_Package my_data14("Marinho");
    Data_Package my_data15("Cantarelli");
    Data_Package my_data16("Baroninho ");
    Data_Package my_data17("Figueiredo");
    Data_Package my_data18("Luis Pereira");
    Data_Package my_data19("Manguito");
    Data_Package my_data20("Roberto Dinamite");
  
    
    Binary_Tree my_tree;
 //Populando a arvore : como ela não é auto balanceável, vamos colocar fora de ordem para nao ficar uma tripa.
    my_tree.insert(&my_data4);
    my_tree.insert(&my_data8);
    my_tree.insert(&my_data1);
    my_tree.insert(&my_data18);
    my_tree.insert(&my_data17);
    my_tree.insert(&my_data7);
    my_tree.insert(&my_data20);
    my_tree.insert(&my_data2);
    my_tree.insert(&my_data20);
    my_tree.insert(&my_data5);
    my_tree.insert(&my_data13);
    my_tree.insert(&my_data3);
    my_tree.insert(&my_data16);
    my_tree.insert(&my_data6);
    my_tree.insert(&my_data11);
    my_tree.insert(&my_data19);
    my_tree.insert(&my_data9);
    my_tree.insert(&my_data14);
    my_tree.insert(&my_data10);
    my_tree.insert(&my_data12);
    my_tree.insert(&my_data15);
    

    
    // Mostrando a árvore
    std::string mermaidCode = my_tree.show_branch(my_tree.root);
    std::cout << "graph TD\n" << mermaidCode << std::endl<<std::endl;
    std::cout<<"Veja em: https://mermaid.live"<<std::endl<<std::endl;

    //Buscando
    std::cout << "Buscando uma chave: " << 4 <<std::endl;
    my_tree.find(4)->data->print();
    std::cout <<std::endl;
    
    
    std::cout << "Pré-Ordem:" << std::endl;
    my_tree.pre_order_traversal(my_tree.root);
    std::cout << "Em-Ordem:" << std::endl;
    my_tree.in_order_traversal(my_tree.root);
    std::cout << "Pós-Ordem:" << std::endl;
    my_tree.post_order_traversal(my_tree.root);
    
    
    my_tree.remove(my_tree.find(20));
    
    return 0;
}
