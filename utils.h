#include <map>
#include <string>
using namespace std;

int generate_adj_matrix(string input_path,
                        map<int, int>& id_map,
                        bool* adj_matrix,
                        int node_size);

int get_feature_and_map_node_id(string node_path,
                                map<int, int>& id_map,
                                float* featrue_map,
                                int featrue_len,
                                int node_len);

int mm(float* A,
       float* B,
       int widA,
       int widB,
       int heightA,
       int heightB,
       float* res);

int relu(float* M, int length);

int softmax(float* V, int length, void* buf);

int load(string filename, float* arr, int length);

int output_matrix(float* matrix, int width, int height);