#pragma once
/*******************************************************************

MultinomialDPM.h		developed by naka_t	2011.02.23

	ガウス分布 Dirichlet Process Mixture

  Copyright (C) 2011  naka_t <naka_t@apple.ee.uec.ac.jp>
 *******************************************************************/
#include "GaussianTable.h"

#define MAX_TABLES 100				// テーブルの最大数（計算用バッファ確保に必要）
#define DP_CONCPARA_PRIOR_A 0.1		// Concentration parameterのガンマ事前分布のパラメタ
#define DP_CONCPARA_PRIOR_B 0.1		// Concentration parameterのガンマ事前分布のパラメタ

class CGaussianDPM
{
public:
	CGaussianDPM(void);
	~CGaussianDPM(void);

	void SetData(double **data, int numData, int dim);	// 訓練データのセット
	void SetData2(double **data, int numData, int dim);     // テストデータのセット
	void Updata();											// パラメータ更新
	void SaveModel(const char *dir);						// モデルの保存
	std::vector<int> GetClusteringResult();					// クラスタリング結果を取得
	std::vector<int> GetClusteringResult2();					// クラスタリング結果を取得

protected:
	void Release();								// メモリ解放
	void Release2();
	int Sampling(double *data);				// 客が座るテーブルのサンプリング
	double SamplingGamma(double oldGamma);	// concentrate paramter のサンプリング
	void DeleteEmptyTables();					// 空のテーブルを削除
	void DeleteTable(int t);					// 特定のテーブルを削除

	int m_numData, m_numData2;								// データ数
	int m_dimData, m_dimData2;								// データの次元
	int *m_dataIndices,*m_dataIndices2;
	double **m_data,**m_data2;							// データ
	int *m_tableID,*m_tableID2;								// データが座ったテーブル
	double m_gamma;
	std::vector<CGaussianTable> m_tables,m_tables2;		// データが座るテーブル
	std::vector<int> m_numTables,m_numTables2;				// 各回でのテーブルの数
	double m_Pz[MAX_TABLES];					// 計算用バッファ

	GaussianParams m_init,m_init2;						// 初期値

};

