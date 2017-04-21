/**
 * Created by LonelyEnvoy on 2017-4-22.
 * Longest Substring Without Repeating Characters
 * Keywords: 滑动窗口法
 */

#define max(a, b) ((a) > (b)) ? (a) : (b)

int pos[256];

int lengthOfLongestSubstring(char* s) {
    int i = 0;
    int j = 0;
    int len = 0;
    char c;
    int lastpos;

    memset(pos, -1, sizeof(pos));
    while ((c = s[j]) != '\0') {
        lastpos = pos[c];
        if (lastpos >= i) {
            i = lastpos + 1;
        }
        pos[c] = j;
        len = max(len, j - i + 1);
        j++;
    }
    return len;
}
