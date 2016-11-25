# mcmc-gs

Gibbs Sampling

[![Build Status](https://travis-ci.org/hiroyam/mcmc-gs.svg?branch=master)](https://travis-ci.org/hiroyam/mcmc-gs)

---

#### これは何？

MCMCのギブスサンプリングのC++によるフルスクラッチです。

パラメタ $w \in \mathcal{R}^d$ を2つの変数に分割して $w = (w_1, w_2)$ とし、目的とする確率分布を $p(w_1, w_2)$ とし、この確率分布から定義される条件付き確率 $p(w_1|w_2)$ および $p(w_2|w_1)$ とした際に、このそれぞれの条件付き確率分布からのサンプリングが容易である場合に使えるMCMCアルゴリズムです。

##### 動作サンプル

多変量正規分布に従う乱数を発生させてみた例です。
![](images/plot1.png)

