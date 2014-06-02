#include <iostream>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int N, W;

	cin >> N >> W;
	int * w = new int[N];
	int * c = new int[N];

	for (int i = 0; i < N; i++)
		cin >> w[i] >> c[i];

	int ** d = new int * [N + 1];

	for (int i = 0; i < N + 1; i++)
		d[i] = new int[W + 1];

	for (int i = 0; i < N + 1; i++)
		d[i][0] = 0;
	for (int i = 0; i < W + 1; i++)
		d[0][i] = 0;

	for (int i = 1; i < N + 1; i++)
		for (int j = 0; j < W + 1; j++)
			if (j >= w[i - 1])
			    d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i - 1]] + c[i - 1]);
			else
				d[i][j] = d[i - 1][j];


	int i = N;
	int j = W;
	vector<int> v;
	while (d[i][j])
	{
		i--;
		if (d[i][j] != d[i + 1][j])
		{
			j -= w[i];
			v.push_back(i + 1);
		}
	}

	cout << v.size() << " " << d[N][W] << endl;
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";

	for (int i = 0; i < N + 1; i++)
		delete [] d[i];
	delete [] d;
	delete [] w;
	delete [] c;
}
