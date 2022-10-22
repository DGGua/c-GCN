int mm(float* A,
       float* B,
       int widA,
       int widB,
       int heightA,
       int heightB,
       float* res);

int relu(float* M, int length);
int softmax(float* V, int length, void* buf);