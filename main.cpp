#include <iostream>
#include "compute.h"
#include "utils.h"
using namespace std;
// #define NODE_CNT 1
#define NODE_CNT 5
#define FEATURE_LENGTH 4
#define HIDDEN_SIZE 3
#define OUTPUT 2
#define ADJ_PATH "input_output/adj.csv"
#define FEATURE_PATH "input_output/nodes.csv"
#define WEIGHT1_PATH "input_output/weight1.csv"
#define WEIGHT2_PATH "input_output/weight2.csv"

int main() {
  float* feature_list =
      (float*)malloc(NODE_CNT * FEATURE_LENGTH * sizeof(float));
  float* adj_matrix = (float*)malloc(NODE_CNT * NODE_CNT * sizeof(float));
  float* weight1 = (float*)malloc(FEATURE_LENGTH * HIDDEN_SIZE * sizeof(float));
  float* weight2 = (float*)malloc(OUTPUT * HIDDEN_SIZE * sizeof(float));
  float* midoutput = (float*)malloc(NODE_CNT * HIDDEN_SIZE * sizeof(float));
  float* output = (float*)malloc(NODE_CNT * OUTPUT * sizeof(float));
  float* buf = (float*)malloc(NODE_CNT * FEATURE_LENGTH * sizeof(float));

  load(ADJ_PATH, adj_matrix, NODE_CNT * NODE_CNT);
  load(FEATURE_PATH, feature_list, NODE_CNT * FEATURE_LENGTH);
  load(WEIGHT1_PATH, weight1, FEATURE_LENGTH * HIDDEN_SIZE);
  load(WEIGHT2_PATH, weight2, HIDDEN_SIZE * OUTPUT);

  cout << "load done" << endl;

  mm(feature_list, weight1, FEATURE_LENGTH, HIDDEN_SIZE, NODE_CNT,
     FEATURE_LENGTH, buf);

  mm(adj_matrix, buf, NODE_CNT, HIDDEN_SIZE, NODE_CNT, NODE_CNT, midoutput);
  relu(midoutput, HIDDEN_SIZE * NODE_CNT);
  mm(midoutput, weight2, HIDDEN_SIZE, OUTPUT, NODE_CNT, HIDDEN_SIZE, buf);
  mm(adj_matrix, buf, NODE_CNT, OUTPUT, NODE_CNT, NODE_CNT, output);
  for (int i = 0; i < NODE_CNT; i++) {
    softmax(output + i * OUTPUT, OUTPUT, buf);
  }
  output_matrix_log(output, OUTPUT, NODE_CNT);
}