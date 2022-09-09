/*

[][][][][][][]

1

[1][][][][][][]

...

[1][2][3][4][5][6][7]

9

[1][2][3][4][5][6][7][9][][][][][][]

*/

typedef struct vector {
    int * data;
    int size;
    int capacity;
} vector_t;

// initializes empty vector with given capacity
void init(vector_t * v, int capacity);

// adds element to the last avaialable position,
// resizes vector if current capacity is reached
void push_back(vector_t * v, int num);
// resizes vector to given capacity
void resize(vector_t * v, int new_capacity);

void set(vector_t * v, int num, int idx);
int at(vector_t * v, int idx);
void destroy(vector_t * v);

int main(int argc, char ** argv) {
    vector_t v;
    init(&v, 8);
    v.data;
    return 0;
}