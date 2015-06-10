
/*******************************************************************

DPMTest.cpp		developed by naka_t	2011.02.23

	DPM�N���X�̎g�p��

  Copyright (C) 2011  naka_t <naka_t@apple.ee.uec.ac.jp>
 *******************************************************************/
#include "stdafx.h"
#include "GaussianDPM.h"
#include "utility.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CGaussianDPM dpm;			// DPM�N���X
	int num, dim;				// �f�[�^���Ǝ���
	std::vector<int> cluster;	//
	std::vector<int> cluster2;
	// �f�[�^�̓ǂݍ��� �P���f�[�^
	double **data = LoadMatrix<double>( dim , num , "GetPositionBase.txt" );

	//�f�[�^�̓ǂݍ��݁@�e�X�g�f�[�^
	double **data2 = LoadMatrix<double>(dim, num, "GetPositionBase.txt");

	// �f�[�^��n�� �P���f�[�^
	dpm.SetData( data , num , dim );

	// �f�[�^��n�� �e�X�g�f�[�^
	dpm.SetData2(data2, num, dim);

	// �p�����^�̍X�V
	for(int i=0 ; i<300 ; i++ )
	{
		printf("i�F%03d\n", i);
		
		dpm.Updata();
	}

	// �w�K���ʕۑ�
	dpm.SaveModel( "result" );
	
	// ���ʂ�\��
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

