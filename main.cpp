#include <iostream>
#include "utils.h"
using namespace std;
// #define NODE_CNT 1
#define NODE_CNT 2708
#define FEATURE_LENGTH 1433
#define HIDDEN_SIZE 16
#define OUTPUT 7
#define NODE_PATH "cora/test.content"
#define EDGE_PATH "cora/cora.cites"

int main() {
  float* feature_map =
      (float*)malloc(NODE_CNT * FEATURE_LENGTH * sizeof(float));
  float* adj_matrix = (float*)malloc(NODE_CNT * NODE_CNT * sizeof(float));
  float* weight1 = (float*)malloc(FEATURE_LENGTH * HIDDEN_SIZE * sizeof(float));
  float* weight2 = (float*)malloc(OUTPUT * HIDDEN_SIZE * sizeof(float));
  float* midoutput = (float*)malloc(NODE_CNT * HIDDEN_SIZE * sizeof(float));
  float* output = (float*)malloc(NODE_CNT * OUTPUT * sizeof(float));
  float* buf = (float*)malloc(NODE_CNT * FEATURE_LENGTH * sizeof(float));

  // map<int, int> id_map;
  // get_feature_and_map_node_id(NODE_PATH, id_map, feature_map,
  // FEATURE_LENGTH,
  //                             NODE_CNT);

  // generate_adj_matrix(EDGE_PATH, id_map, adj_matrix, NODE_CNT);
  // for (int i = 0; i < NODE_CNT; i++) {
  //   for (int j = 0; j < NODE_CNT; j++) {
  //     cout << (adj_matrix[i * NODE_CNT + j] ? "1" : "0");
  //     if (j < NODE_CNT - 1) {
  //       cout << "\t";
  //     }
  //   }
  //   cout << endl;
  //  }
  load("test.in", buf, 1);
  cout << buf[0] << "1" << endl;
  // load("adj.in", adj_matrix, NODE_CNT * NODE_CNT);
  // load("feat.in", feature_map, NODE_CNT * FEATURE_LENGTH);
  // load("weight1.in", weight1, FEATURE_LENGTH * HIDDEN_SIZE);
  // load("weight2.in", weight2, HIDDEN_SIZE * OUTPUT);

  // cout << "load done" << endl;

  // mm(feature_map, weight1, FEATURE_LENGTH, HIDDEN_SIZE, NODE_CNT,
  //    FEATURE_LENGTH, buf);

  // output_matrix(buf, HIDDEN_SIZE, 1);
  // mm(adj_matrix, buf, NODE_CNT, HIDDEN_SIZE, NODE_CNT, NODE_CNT, midoutput);
  // relu(midoutput, HIDDEN_SIZE * NODE_CNT);
  // output_matrix(midoutput, HIDDEN_SIZE, 1);
  // mm(midoutput, weight2, HIDDEN_SIZE, OUTPUT, NODE_CNT, HIDDEN_SIZE, buf);
  // output_matrix(buf, OUTPUT, 1);
  // mm(adj_matrix, buf, NODE_CNT, OUTPUT, NODE_CNT, NODE_CNT, output);
  // output_matrix(output, OUTPUT, 1);
  // for (int i = 0; i < NODE_CNT; i++) {
  //   softmax(output + i * OUTPUT, OUTPUT, buf);
  // }
  // output_matrix(output, OUTPUT, NODE_CNT);
}