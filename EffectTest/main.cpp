#include <Novice.h>
#include <Vector2D.h>
#include <MyFunc.h>

/******** ウィンドウ名の指定 **********/
const char kWindowTitle[] = "sampleEffect";

/******** ウィンドウサイズの指定 **********/
const int kWinodowWidth = 1280; //x
const int kWindowHeight = 720; //y

/*********************************
    定数の宣言ここまで
*********************************/

/*********************************
	構造体宣言ここから
*********************************/

/******** エフェクト **********/
//position ... x, y座標
//size ... 矩形のサイズ
//velocity ... 動く速度
//acceleration ... 加速度
//elapseFrame ... 存在時間
//isEnd ... エフェクトが終了しているか
struct Effect {
	Vector2D position;
	Vector2D size;
	Vector2D velocity;
	float acceleration;
	int elapseFrame;
	bool isEnd;
};

/*********************************
	構造体宣言ここまで
*********************************/

/*********************************
	関数の処理ここから
*********************************/

/******** サンプルエフェクトの更新処理 **********/
void sampleEffectUpdate(Effect &effect) {

	//エフェクトの経過フレームが一定値を超えるか、エフェクトの横幅が0になったら
	if (effect.elapseFrame >= 100 || effect.size.x <= 0) {

		//エフェクトを終了させる
		effect.isEnd = true;

		//エフェクト位置を初期化
		effect.position.y = 0.0f;
		effect.velocity.y = 0.98f;
		effect.elapseFrame = 0;
	}
	else if(effect.isEnd == false) {

		//エフェクトを画面上から下に動かす
		effect.position.y += effect.velocity.y;
		effect.velocity.y += effect.acceleration;
		effect.size.x -= effect.acceleration;

		//エフェクトの存在時間をプラス
		effect.elapseFrame++;
	}

}

/*********************************
	関数の処理ここまで
*********************************/

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWinodowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	/*********************************
		変数宣言ここから
	*********************************/

	//乱数
	My::SetSrand();

	//経過フレーム記録
	int frame = 0;

	//矩形用テクスチャ読み込み
	int sampleTexture = Novice::LoadTexture("white1x1.png");

	/******** エフェクト関係 **********/
	//表示可能エフェクト数
	const int maxEffects = 30;

	//エフェクト初期化
	Effect sampleEffect[maxEffects];
	for (int i = 0; i < maxEffects; i++) {
		sampleEffect[i] = {
			{0.0f , 0.0f},
			{0.0f , 0.0f},
			{0.0f, 0.98f},
			0.1f,
			0,
			true
		};
	}

	/*********************************
		変数宣言ここまで
	*********************************/

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/*********************************
			更新処理ここから
		*********************************/

		//経過フレームプラス
		frame++;

		/******** エフェクト更新処理 **********/
		for (int i = 0; i < maxEffects; i++) {

			//経過フレームが一定値以上になったら
			if (frame >= 15) {
				if (sampleEffect[i].isEnd == true) {

					//エフェクト位置とサイズをランダムな位置に指定
					sampleEffect[i].position.x = My::RandomF(0.0f, 1280.0f, 0);
					sampleEffect[i].size = { My::RandomF(5.0f, 15.0f, 0), My::RandomF(5.0f, 15.0f, 0) };

					//エフェクト出現
					sampleEffect[i].isEnd = false;
					frame = 0;
				}
			}

			//エフェクト更新
			sampleEffectUpdate(sampleEffect[i]);

		}

		/*********************************
			更新処理ここまで
		*********************************/

		/*********************************
			描画処理ここから
		*********************************/

		/******** エフェクト描画 **********/
		for (int i = 0; i < maxEffects; i++) {
			if (!sampleEffect[i].isEnd) {

				Novice::DrawQuad(
					sampleEffect[i].position.x - sampleEffect[i].size.x,
					sampleEffect[i].position.y + sampleEffect[i].size.y,

					sampleEffect[i].position.x + sampleEffect[i].size.x,
					sampleEffect[i].position.y + sampleEffect[i].size.y,

					sampleEffect[i].position.x - sampleEffect[i].size.x,
					sampleEffect[i].position.y - sampleEffect[i].size.y,

					sampleEffect[i].position.x + sampleEffect[i].size.x,
					sampleEffect[i].position.y - sampleEffect[i].size.y,

					0, 0,
					1, 1,

					sampleTexture,
					WHITE
				);

			}
		}

		Novice::ScreenPrintf(0, 10, "elapseFrame : %d", sampleEffect[0].elapseFrame);
		Novice::ScreenPrintf(0, 30, "effectAppearTime : %d", frame);

		/*********************************
			描画処理ここまで
		*********************************/

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
