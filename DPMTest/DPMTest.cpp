
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

	// �f�[�^�̓ǂݍ���
	double **data = LoadMatrix<double>( dim , num , "GetPositionBase.txt" );

	// �f�[�^��n��
	dpm.SetData( data , num , dim );

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

	Free( data );

	return 0;
}

