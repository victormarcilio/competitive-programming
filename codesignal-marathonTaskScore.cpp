//https://app.codesignal.com/company-challenges/codesignal/68DxrkM9yXirF4fuD
int marathonTaskScore(int marathonLength, int maxScore, int submissions, int successfulSubmissionTime) {
    if(successfulSubmissionTime == -1)
        return 0;
    return max(maxScore >> 1, maxScore - 10*(submissions - 1) - successfulSubmissionTime * maxScore/2 / marathonLength);
}
