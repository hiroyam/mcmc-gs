#include "./util.hpp"

using namespace cc;

void update(vec_t &v, int i) {
    const vec_t              u   {5.0f, 2.0f};
    const std::vector<vec_t> cov {{8.0f, -1.0f}, {-1.0f, 2.0f}};

    int j = 1 - i; // 1=>0 or 0=>1

    // 多変量正規分布の条件付き分布
    v[i] = gaussian_rand(u[i] - (v[j] - u[j]) * cov[i][j] / cov[i][i], std::sqrt(1.0f / cov[i][i]));
}

int main(int argc, char *argv[]) {
    try {
        std::vector<vec_t> samples;
        const int          n_loop = 10000;

        vec_t v(2);
        for (int i = 0; i < n_loop; i++) {
            // ランダムに片方を固定してもう片方を動かす
            if (uniform_rand(0, 1)) {
                update(v, 0);
            } else {
                update(v, 1);
            }
            samples.push_back(v);
        }

        // バーンイン期間を破棄する
        const int n_burnin = samples.size() / 10;
        std::rotate(samples.begin(), samples.begin() + n_burnin, samples.end());
        samples.resize(samples.size() - n_burnin);

        // プロットする
        std::ofstream ofs("output");
        for (auto v : samples) {
            ofs << format_str("%f %f", v[0], v[1]) << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << colorant('y', format_str("error: %s", e.what())) << std::endl;
    }
}
