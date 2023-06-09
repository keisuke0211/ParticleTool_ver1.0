//========================================
// カメラの処理 
// Author:大殿慶輔
//========================================
#include "camera.h"
#include "input.h"
//========================================
// グローバル変数
//========================================
Camera g_camera[MAX_CAMERA];		//カメラの情報

float ra, rb, rc;
//========================================
// 初期化処理
//========================================
void InitCamera(void)
{
	for (int nCntCma = 0; nCntCma < MAX_CAMERA; nCntCma++)
	{
		if (nCntCma == 0)
		{
			g_camera[nCntCma].posV = D3DXVECTOR3(0.0f, 210.0f, -340.0f);	//カメラの位置 0 110 -240
			g_camera[nCntCma].posR = D3DXVECTOR3(0.0f, 110.0f, -100.0f);	//見る場所
			g_camera[nCntCma].vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			g_camera[nCntCma].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//向き
			g_camera[nCntCma].spin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//回転量
			g_camera[nCntCma].viewport.X = 0.0f;
			g_camera[nCntCma].viewport.Y = 0.0f;
			g_camera[nCntCma].viewport.Width = 1280.0f;
			g_camera[nCntCma].viewport.Height = 720.0f;
			g_camera[nCntCma].bUse = true;
			g_camera[nCntCma].bFog = true;
		}

		g_camera[nCntCma].viewport.MinZ = 0.0;
		g_camera[nCntCma].viewport.MaxZ = 1.0f;
		ra = DEFAULT_FLOA;
		rb = DEFAULT_FLOA;
		rc = DEFAULT_FLOA;
	}
	
	
}
//========================================
// 終了処理
//========================================
void UninitCamera(void)
{

}
//****************************************
// 更新処理
//****************************************
void UpdateCamera(void)
{
	for (int nCntCma = 0; nCntCma < MAX_CAMERA; nCntCma++)
	{
		g_camera[nCntCma].posOldV = g_camera[nCntCma].posV;
		g_camera[nCntCma].posOldR = g_camera[nCntCma].posR;

		ra = g_camera[nCntCma].posV.x - g_camera[nCntCma].posR.x;
		rb = g_camera[nCntCma].posV.z - g_camera[nCntCma].posR.z;
		g_camera[nCntCma].length = sqrtf(ra * ra + rb * rb);

		//上下移動
		if (GetKeyboardPress(DIK_A) == true)
		{
			if (GetKeyboardPress(DIK_W) == true)
			{
				g_camera[0].posV.x += sinf(D3DX_PI * (-DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posV.z += cosf(D3DX_PI * (-DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

				g_camera[0].posR.x += sinf(D3DX_PI * (-DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posR.z += cosf(D3DX_PI * (-DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			}
			else if (GetKeyboardPress(DIK_S) == true)
			{
				g_camera[0].posV.x += sinf(D3DX_PI * (-DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posV.z += cosf(D3DX_PI * (-DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

				g_camera[0].posR.x += sinf(D3DX_PI * (-DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posR.z += cosf(D3DX_PI * (-DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			}
			else
			{
				g_camera[0].posV.x += sinf(D3DX_PI * (-BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posV.z += cosf(D3DX_PI * (-BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

				g_camera[0].posR.x += sinf(D3DX_PI * (-BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posR.z += cosf(D3DX_PI * (-BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			}
		}
		else if (GetKeyboardPress(DIK_D) == true)
		{
			if (GetKeyboardPress(DIK_W) == true)
			{
				g_camera[0].posV.x += sinf(D3DX_PI * (DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posV.z += cosf(D3DX_PI * (DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

				g_camera[0].posR.x += sinf(D3DX_PI * (DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posR.z += cosf(D3DX_PI * (DIAGONALLY_UP - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			}
			else if (GetKeyboardPress(DIK_S) == true)
			{
				g_camera[0].posV.x += sinf(D3DX_PI * (DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posV.z += cosf(D3DX_PI * (DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

				g_camera[0].posR.x += sinf(D3DX_PI * (DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posR.z += cosf(D3DX_PI * (DIAGONALLY_DOWN - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			}
			else
			{
				g_camera[0].posV.x += sinf(D3DX_PI * (BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posV.z += cosf(D3DX_PI * (BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

				g_camera[0].posR.x += sinf(D3DX_PI * (BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
				g_camera[0].posR.z += cosf(D3DX_PI * (BESIDE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			}
		}
		else if (GetKeyboardPress(DIK_W) == true)
		{
			g_camera[0].posV.x += sinf(D3DX_PI * (ABOVE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			g_camera[0].posV.z += cosf(D3DX_PI * (ABOVE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

			g_camera[0].posR.x += sinf(D3DX_PI * (ABOVE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			g_camera[0].posR.z += cosf(D3DX_PI * (ABOVE - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

		}
		else if (GetKeyboardPress(DIK_S) == true)
		{
			g_camera[0].posV.x += sinf(D3DX_PI * (UNDER - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			g_camera[0].posV.z += cosf(D3DX_PI * (UNDER - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

			g_camera[0].posR.x += sinf(D3DX_PI * (UNDER - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;
			g_camera[0].posR.z += cosf(D3DX_PI * (UNDER - g_camera[nCntCma].rot.z)) * CAMERA_SPEED;

		}

		//視点・上下移動
		if (GetKeyboardPress(DIK_G) == true)
		{
			g_camera[0].posV.y += cosf(D3DX_PI * ABOVE) * CAMERA_SPEED1;
			g_camera[0].posR.y += cosf(D3DX_PI * ABOVE) * CAMERA_SPEED1;
		}
		else if (GetKeyboardPress(DIK_B) == true)
		{
			g_camera[0].posV.y += cosf(D3DX_PI * UNDER) * CAMERA_SPEED1;
			g_camera[0].posR.y += cosf(D3DX_PI * UNDER) * CAMERA_SPEED1;
		}

		//横の回転・視点
		if (GetKeyboardPress(DIK_Z) == true)
		{
			g_camera[0].rot.z -= ROT_SPEED;

			g_camera[0].posV.x = g_camera[0].posR.x + sinf(D3DX_PI * (1.0f - g_camera[0].rot.z)) * g_camera[0].length;
			g_camera[0].posV.z = g_camera[0].posR.z + cosf(D3DX_PI * (1.0f - g_camera[0].rot.z)) * g_camera[0].length;

		}
		else if (GetKeyboardPress(DIK_C) == true)
		{
			g_camera[0].rot.z += ROT_SPEED;

			g_camera[0].posV.x = g_camera[0].posR.x + sinf(D3DX_PI * (1.0f - g_camera[0].rot.z)) * g_camera[0].length;
			g_camera[0].posV.z = g_camera[0].posR.z + cosf(D3DX_PI * (1.0f - g_camera[0].rot.z)) * g_camera[0].length;
		}

		//横の回転・注視点
		if (GetKeyboardPress(DIK_Q) == true)
		{
			g_camera[0].rot.z -= ROT_SPEED;

			g_camera[0].posR.x = g_camera[0].posV.x + sinf(D3DX_PI * g_camera[0].rot.z) * g_camera[0].length;
			g_camera[0].posR.z = g_camera[0].posV.z + cosf(D3DX_PI * g_camera[0].rot.z) * g_camera[0].length;

		}
		else if (GetKeyboardPress(DIK_E) == true)
		{
			g_camera[0].rot.z += 0.01f;

			g_camera[0].posR.x = g_camera[0].posV.x + sinf(D3DX_PI * g_camera[0].rot.z) * g_camera[0].length;
			g_camera[0].posR.z = g_camera[0].posV.z + cosf(D3DX_PI * g_camera[0].rot.z) * g_camera[0].length;
		}

	}
}
//****************************************
// 設定処理
//****************************************
void SetCamera(int nldx)
{
	//デバイスの所得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//ビューポートの設定
	pDevice->SetViewport(&g_camera[nldx].viewport);

	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&g_camera[nldx].mtxProjection);

	//プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&g_camera[nldx].mtxProjection,
		D3DXToRadian(36.0f),						/* 視野角 */
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,	/*画面のアスペクト比*/
		10.0f,										/*Z値の最小値*/
		5000.0f);									/*Z値の最大値*/

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &g_camera[nldx].mtxProjection);

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&g_camera[nldx].mtxView);

	//ビューマトリックスの作成
	D3DXMatrixLookAtLH(&g_camera[nldx].mtxView,
		&g_camera[nldx].posV,			/*視点*/
		&g_camera[nldx].posR,			/*注視点*/
		&g_camera[nldx].vecU);			/*上方向ベクトル*/

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &g_camera[nldx].mtxView);
}
Camera *Getcamara(int nCntCamara)
{
	return &g_camera[nCntCamara];
}