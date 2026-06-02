#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int n = landDuration.size(), m = waterDuration.size();
    int ans = 2E9;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (landStartTime[i] + landDuration[i] < landStartTime[a] + landDuration[a]) {
        a = i;
      }
    }
    for (int i = 0; i < m; i++) {
      if (waterStartTime[i] + waterDuration[i] < waterStartTime[b] + waterDuration[b]) {
        b = i;
      }
      if (waterStartTime[i] + waterDuration[i] <= landStartTime[a]) {
        ans = min(ans, landStartTime[a] + landDuration[a]);
      } else if (waterStartTime[i] <= landStartTime[a] + landDuration[a]) {
        ans = min(ans, landStartTime[a] + landDuration[a] + waterDuration[i]);
      } else {
        ans = min(ans, waterStartTime[i] + waterDuration[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (landStartTime[i] + landDuration[i] <= waterStartTime[b]) {
        ans = min(ans, waterStartTime[b] + waterDuration[b]);
      } else if (landStartTime[i] <= waterStartTime[b] + waterDuration[b]) {
        ans = min(ans, waterStartTime[b] + waterDuration[b] + landDuration[i]);
      } else {
        ans = min(ans, landStartTime[i] + landDuration[i]);
      }
    }
    return ans;
  }
};