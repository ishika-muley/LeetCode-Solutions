1class OrderedStream {
2public:
3    vector<string> stream;
4    int ptr;
5
6    OrderedStream(int n) {
7        stream.resize(n);
8        ptr = 0;
9    }
10
11    vector<string> insert(int idKey, string value) {
12        stream[idKey - 1] = value;
13        vector<string> result;
14
15        while (ptr < stream.size() && stream[ptr] != "") {
16            result.push_back(stream[ptr]);
17            ptr++;
18        }
19
20        return result;
21    }
22};