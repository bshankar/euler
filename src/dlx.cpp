#include "dlx.h"

dlx::dlx(const vvb& matrix, void (*printPtr)(node*)) {
    initLinks(matrix);
    this->printPtr = printPtr;
}


void dlx::initLinks(const vvb& matrix) {
    // Create the data structure for the dlx algorithm
    root      = new link();
    thisHead = new link();

    const ui ROWS = matrix.size();
    const ui COLNS = matrix[0].size();
    colnHeaders.resize(COLNS);

    root->right = thisHead;
    thisHead->left = root;
    thisHead->name = 0;
    thisHead->size = 0;
    colnHeaders[0] = thisHead;

    // create and link all column headers
    for (ui i = 1; i < COLNS; ++i) {
        tmpHead = new link();
        tmpHead->name = i;
        tmpHead->size = 0;
        thisHead->right = tmpHead;
        tmpHead->left = thisHead;
        thisHead = tmpHead;
        colnHeaders[i] = thisHead;
    }

    colnHeaders[COLNS-1]->right = root;
    root->left = colnHeaders[COLNS-1];

    // store immediately above and left
    vector<node> above(COLNS);
    vector<node> before(ROWS);

    for (ui i = 0; i < ROWS; ++i) {
        for (ui j = 0; j < COLNS; ++j) {
            if (matrix[i][j]) {
                tmpRow = new link();
                tmpRow->name = i;
                tmpRow->coln = colnHeaders[j];
                ++tmpRow->coln->size;

                // vertical links
                if (above[j] == NULL) {
                    colnHeaders[j]->down = tmpRow;
                    tmpRow->up = colnHeaders[j];
                }
                else {
                    above[j]->down = tmpRow;
                    tmpRow->up = above[j];
                }
                above[j] = tmpRow;

                // horizontal links
                if (before[i] != NULL) {
                    before[i]->right = tmpRow;
                    tmpRow->left = before[i];
                }
                before[i] = tmpRow;
            }
        }
    }

    // make colns circular
    for (ui i = 0; i < COLNS; ++i) {
        colnHeaders[i]->up = above[i];
        above[i]->down = colnHeaders[i];
    }

    // make rows circular
    for (ui i = 0; i < ROWS; ++i) {
        node f_row = before[i]->left->left->left;
        before[i]->right = f_row;
        f_row->left = before[i];
    }
}


void dlx::chooseColn() {

    minColn = root->right;
    minSize = root->right->size;
    for (node cH = root->right; cH != root; cH = cH->right) {
        
        if (cH->size == 1) {
            minSize = 1;
            minColn = cH;
            break;
        }

        if (cH->size < minSize) {
            minColn = cH;
            minSize = cH->size;
        }
    }
}


void dlx::cover(node c) {
    
    // remove c from column headers
    c->left->right = c->right;
    c->right->left = c->left;

    for (node  i = c->down; i != c; i = i->down) {
        for (node j = i->right; j != i; j = j->right) {

            // remove j from its column
            j->down->up = j->up;
            j->up->down = j->down;
            --j->coln->size;
        }
    }
}


void dlx::uncover(node c) {

    for (node  i = c->up; i != c; i = i->up) {
        for (node j = i->left; j != i; j = j->left) {
            // add back j to its column
            ++j->coln->size;
            j->up->down = j;
            j->down->up = j;
        }
    }
    
    // add back c to column headers
    c->left->right = c;
    c->right->left = c;
}


void dlx::search(ui k) {

    if (root->right == root) {
        printSolution();
        return;
    }

    chooseColn();
    node c = minColn;
    cover(c);

    for (node  r = c->down; r != c; r = r->down) {
        solution[k] = r;

        for (node j = r->right; j != r; j = j->right)
            cover(j->coln);

        search(k+1);
        r = solution[k];
        c = r->coln;

        for (node j = r->left; j != r; j = j->left)
            uncover(j->coln);
    }
    uncover(c);
    return;
}


void dlx::printSolution() {
    printPtr(solution);
}