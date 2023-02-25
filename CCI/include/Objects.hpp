class Node {
  public:
    int value;
    Node* left;
    Node* right;

    Node(int iValue, Node* iLeft = nullptr, Node* iRight = nullptr): value(iValue), left(iLeft), right(iRight){}
};

Node* getIncompleteBinaryTree(){
  Node* n3_1 = new Node(3);
  Node* n3_2 = new Node(7);
  Node* n3_3 = new Node(30);

  Node* n2_1 = new Node(5, n3_1, n3_2);
  Node* n2_2 = new Node(20, nullptr, n3_3);

  Node* n1 = new Node(10, n2_1, n2_2);
  return n1;
}