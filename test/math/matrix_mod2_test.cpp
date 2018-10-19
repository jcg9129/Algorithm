#include "gtest/gtest.h"
#include "algotest/math/matrix_mod2_test.h"

using namespace algotest;

#include "base.h"
#include "math/modint.h"
#include "math/matrix.h"


struct MatMod2MintTester : public MatrixMod2TesterBase {
    using Mint = ModInt<2>;
    int rank(VV<int> _mat) final {
        V<Vec<Mint>> mat;
        for (auto v: _mat) {
            mat.push_back({});
            for (auto d: v) mat.back().push_back(d);
        }
        return calc_rank(mat);
    }
    V<int> linear_equation(VV<int> _mat, V<int> _vec) final {
        V<Vec<Mint>> mat;
        for (auto v: _mat) {
            mat.push_back({});
            for (auto d: v) mat.back().push_back(d);
        }
        Vec<Mint> vec;
        for (auto d: _vec) vec.push_back(d);
        auto res = solve_linear(mat, vec);
        V<int> _res;
        for (auto d: res) _res.push_back(d.v);
        return _res;
    }
};

struct MatMod2BitVecTester : public MatrixMod2TesterBase {

    int rank(VV<int> _mat) final {
        V<BitVec> mat;
        for (auto v: _mat) {
            mat.push_back({});
            for (auto d: v) mat.back().push_back(d);
        }
        return calc_rank(mat);
    }
    V<int> linear_equation(VV<int> _mat, V<int> _vec) final {
        V<BitVec> mat;
        for (auto v: _mat) {
            mat.push_back({});
            for (auto d: v) mat.back().push_back(d);
        }
        BitVec vec;
        for (auto d: _vec) vec.push_back(d);
        auto res = solve_linear(mat, vec);
        V<int> _res;
        for (int i = 0; i < int(res.size()); i++) _res.push_back(res[i]);
        return _res;
    }
};

using MatrixMod2Types = ::testing::Types<MatMod2MintTester, MatMod2BitVecTester>;
INSTANTIATE_TYPED_TEST_CASE_P(MyMatrixMod, MatrixMod2Test, MatrixMod2Types);