#ifndef TINYRNN_STANDALONE_GUARD_d6b80c7dd9ae4f1e887fe064c13ec7d32840a49a15066a4f58d40a912a2f7bb3
#define TINYRNN_STANDALONE_GUARD_d6b80c7dd9ae4f1e887fe064c13ec7d32840a49a15066a4f58d40a912a2f7bb3

extern float kMemory[];
const int kMemorySize = 8864515;

extern float kOutputs[];
const int kOutputsSize = 64;

void GoDeeperFeed(const float *input);
void GoDeeperTrain(const float rate, const float *target);

#endif //TINYRNN_STANDALONE_GUARD_d6b80c7dd9ae4f1e887fe064c13ec7d32840a49a15066a4f58d40a912a2f7bb3
