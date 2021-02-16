#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int address;
	int data;
	int next;
};

int data_[1000010];
int next_[1000010];

int main()
{
	int first, n, k, cnt = 0;
	cin >> first >> n >> k;
	int thisaddress, thisdata, thisnext;
	for (int i = 0; i < n; i++) {
		cin >> thisaddress >> thisdata >> thisnext;
		data_[thisaddress] = thisdata;
		next_[thisaddress] = thisnext;
	}
	//从第一个节点开始组装并放入vector容器中
	vector<Node> v;
	while (first != -1) {
		Node node;
		node.address = first;
		node.data = data_[first];
		node.next = next_[first];
		v.push_back(node);
		first = node.next;
	}
	//每k个反转
	for (int i = 0; i+k <= v.size(); i+=k) {	//012 345 67
		reverse(v.begin()+i,v.begin()+i+k);
	}
	//打印列表
	cnt = v.size();
	for (int i = 0; i < cnt-1; i++) {
		printf("%05d %d %05d\n",v[i].address,v[i].data,v[i+1].address);
	}
	printf("%05d %d -1", v[cnt - 1].address, v[cnt - 1].data);
	return 0;
}
