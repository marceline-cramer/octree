#include <iostream>
using namespace std;

#include "octree.h"

#include <stdlib.h>

void Subdivide(Octree* root, int depth, int chance) {
    int* stack = new int[depth];
    Octree** octStack = new Octree*[depth];
    Octree** parStack = new Octree*[depth];
    int z = 0;

    for(int i = 0; i < depth; i++) {
        stack[i] = 0;
        octStack[i] = NULL;
        parStack[i] = root;
    }

    while(z >= 0) {
        if(stack[z] > 7) {
            z--;
        } else {
            octStack[z] = parStack[z]->Subdivide(stack[z]++);
            if(z+1 < depth && rand()%256 > chance) {
                z++;
                parStack[z] = octStack[z-1];
                stack[z] = 0;
            }
        }
    }

    delete[] stack;
    delete[] octStack;
    delete[] parStack;
}

int main() {
    Octree* root = new Octree();
    Subdivide(root, 8, 0);
    root->Print();
    delete root;

    cout << "Press enter to continue..." << endl;
    cin.get();
    return 0;
}
