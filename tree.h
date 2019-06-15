#ifndef TREE_H
#define TREE_H
#include <QTextEdit>

class Tree
{



public:
   void add(qreal _data);
    Tree();
    virtual ~Tree();
    unsigned int height();
    void print(QTextEdit *memo);
    void balanc();
    void clear();
private:
    struct TTree{
        qreal data;
        TTree *right;
        TTree *left;
    };
    TTree *tree;
    void addRec(TTree *&_tree, qreal _data);
    void deleteTree(TTree *&_tree);
    unsigned int heightRec(TTree *_tree);
    void printRec(TTree *_tree, int rang, double **_matrix);
    //void balanceRec(TTree *&_tree);
    bool smallLeftTurn(TTree *&_tree);
    bool smallRightTurn(TTree *&_tree);
    bool bigLeftTurn(TTree *&_tree);
    bool bigRightTurn(TTree *&_tree);
};

#endif // TREE_H
