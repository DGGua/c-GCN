#include "utils.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int generate_adj_matrix(string input_path,
                        map<int, int>& id_map,
                        bool* adj_matrix,
                        int node_size) {
  ifstream fin;
  fin.open(input_path, ios::in);

  if (!fin.is_open()) {
    cerr << "read adj file fail" << endl;
    return 1;
  }
  int source, dest;
  while (fin >> source >> dest) {
    if (id_map.find(source) == id_map.end() ||
        id_map.find(dest) == id_map.end()) {
      cerr << "raw node id " << source << " " << dest << " map not found";
      return 1;
    }
    source = id_map[source];
    dest = id_map[dest];
    adj_matrix[source * node_size + dest] = true;
  }
  return 0;
}

int get_feature_and_map_node_id(string node_path,
                                map<int, int>& id_map,
                                float* featrue_map,
                                int featrue_len,
                                int node_len) {
  ifstream fin;
  fin.open(node_path, ios::in);

  if (!fin.is_open()) {
    cerr << "read node file fail" << endl;
    return 1;
  }
  int tempid;
  for (int i = 0; i < node_len; i++) {
    fin >> tempid;
    id_map[tempid] = i;
    for (int j = 0; j < featrue_len; j++) {
      fin >> featrue_map[i * featrue_len + j];
    }
  }
  return 0;
}

int load(string filename, float* arr, int length) {
  ifstream fin;
  fin.open(filename, ios::in);
  if (!fin.is_open()) {
    cerr << "open file " << filename << " fail" << endl;
    return 1;
  }

  for (int i = 0; i < length; i++) {
    fin >> arr[i];
  }
  return 0;
}

int output_matrix(float* matrix, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << matrix[i * width + j];
      if (j < width - 1) {
        cout << "\t";
      }
    }
    cout << endl;
  }
  cout << endl;
}

int output_matrix_log(float* matrix, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << log(matrix[i * width + j]);
      if (j < width - 1) {
        cout << "\t";
      }
    }
    cout << endl;
  }
  cout << endl;
}