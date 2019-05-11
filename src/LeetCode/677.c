/**
 * Created by lonelyenvoy on 2019-05-11.
 * Map Sum Pairs
 * Keywords: prefix tree
 */

#define MAX 255

typedef struct MapSum {
    int value;
    int sum;
    struct MapSum* next;
} MapSum;

/** Initialize your data structure here. */

MapSum* mapSumCreate() {
    MapSum* root = (MapSum*) malloc(sizeof(MapSum));
    root->value = 0;
    root->sum = 0;
    root->next = NULL;
    return root;
}

int _mapSumInsert(MapSum* obj, char* key, int val, int len, int depth) {
    if (depth == len) {
        int delta = val - obj->value;
        obj->value = val;
        obj->sum += delta;
        return delta;
    }
    if (obj->next == NULL) {
        obj->next = (MapSum*) malloc(MAX * sizeof(MapSum));
        for (int i = 0; i < MAX; i++) {
            (obj->next + i)->value = 0;
            (obj->next + i)->sum = 0;
            (obj->next + i)->next = NULL;
        }
    }
    MapSum* target = obj->next + *(key + depth);
    int delta = _mapSumInsert(target, key, val, len, depth + 1);
    obj->sum += delta;
    return delta;
}

void mapSumInsert(MapSum* obj, char* key, int val) {
    if (!obj || !key) return;
    _mapSumInsert(obj, key, val, strlen(key), 0);
}

int mapSumSum(MapSum* obj, char* prefix) {
    if (!obj || !prefix) return 0;
    int len = strlen(prefix);
    MapSum* root = obj;
    for (int i = 0; i < len; i++) {
        MapSum* node = root->next + *(prefix + i);
        if (node->next == NULL) {
            return (i == len - 1) ? node->value : 0;
        }
        root = node;
    }
    return root->sum;
}

void mapSumFree(MapSum* obj) {
    if (!obj) return;
    if (obj->next) {
        mapSumFree(obj->next);
    }
    free(obj);
}


/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);

 * int param_2 = mapSumSum(obj, prefix);

 * mapSumFree(obj);
*/
