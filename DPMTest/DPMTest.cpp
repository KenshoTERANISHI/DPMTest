
/*******************************************************************

DPMTest.cpp		developed by naka_t	2011.02.23

	DPMクラスの使用例

  Copyright (C) 2011  naka_t <naka_t@apple.ee.uec.ac.jp>
 *******************************************************************/
#include "stdafx.h"
#include "GaussianDPM.h"
#include "utility.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CGaussianDPM dpm;			// DPMクラス
	int num, dim;				// データ数と次元
	std::vector<int> cluster;	//
	std::vector<int> cluster2;
	// データの読み込み 訓練データ
	double **data = LoadMatrix<double>( dim , num , "GetPositionBase.txt" );

	//データの読み込み　テストデータ
	double **data2 = LoadMatrix<double>(dim, num, "GetPositionBase.txt");

	// データを渡す 訓練データ
	dpm.SetData( data , num , dim );

	// データを渡す テストデータ
	dpm.SetData2(data2, num, dim);

	// パラメタの更新
	for(int i=0 ; i<300 ; i++ )
	{
		printf("i：%03d\n", i);
		
		dpm.Updata();
	}

	// 学習結果保存
	dpm.SaveModel( "result" );
	
	// 結果を表示
	cluster = dpm.GetClusteringResult();
	for(int i=0 ; i<cluster.size() ; i++ )
	{
		printf("%d	->	%d\n" , i , cluster[i] );
	}
	
	cluster2 = dpm.GetClusteringResult2();
	for (int i = 0; i<cluster2.size(); i++)
	{
		printf("%d	->	%d\n", i, cluster2[i]);
	}
	
	Free( data );
	Free(data2);
	return 0;
}

