#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int D = 70;
const int mod = 42373;

struct Matrix {
    vector< vector<int> > mat;
    int n_rows, n_cols;

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n) {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }
    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                for(int k = 0; k < n_cols; k++) 
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % mod;
        return Matrix(result);
    }
};

Matrix fast_exponentiation(Matrix m, int power) {
    Matrix result = Matrix::identity_matrix(m.n_rows);
    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    } return result;
}
int main(int argc, char const *argv[]) {
	int n; cin>>n; 
	vector<vector<int> > m(n, vector<int>(n));
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			cin>>m[i][j];
	int u, v, k;
	cin>>u>>v>>k;
	Matrix mat(m);
	mat = fast_exponentiation(mat, k);
	ll ans = mat.mat[u-1][v-1];
	if(ans != 34443) cout<<ans<<endl;
}