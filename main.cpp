#include <Novice.h>
#define _USE_MATH_DEFINES
#include <Math.h>

struct Vec3 {
	float x;
	float y;
	float z;
};

//加算
Vec3 Add(const Vec3 &v1 , const Vec3 &v2) {
	Vec3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

//減算
Vec3 Subtract(const Vec3 &v1 , const Vec3 &v2) {
	Vec3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

//スカラー倍
Vec3 Multiply(float scaler , Vec3 &v) {
	Vec3 result;
	result.x = v.x * scaler;
	result.y = v.y * scaler;
	result.z = v.z * scaler;
	return result;
}

//内積
float Dot(const Vec3 &v1 , const Vec3 &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//長さ(ノルム)
float Length(const Vec3 &v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

//正規化
Vec3 Normalize(const Vec3 &v) {
	Vec3 result;
	result.x = v.x / Length(v);
	result.y = v.y / Length(v);
	result.z = v.z / Length(v);
	return result;
}

//VectorScreenPrintf
static const int kColumnWidth = 60;
void VectorScreenPrintf(int x , int y , const Vec3 &vector , const char *label) {
	Novice::ScreenPrintf(x , y , "%.02f" , vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y , "%.02f" , vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y , "%.02f" , vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y , "%s" , label);
}

const char kWindowTitle[] = "LD2B_06_ナガトモイチゴ_MT3_00_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//宣言・初期化
	Vec3 v1 = {1.0f, 3.0f, -5.0f};
	Vec3 v2 = {4.0f, -1.0f, 2.0f};
	float k = 4.0f;

	Vec3 resultAdd = Add(v1, v2);
	Vec3 resultSubtract = Subtract(v1 , v2);
	Vec3 resultMultiply = Multiply(k , v1);
	float resultDot = Dot(v1 , v2);
	float resultLength = Length(v1);
	Vec3 resultNormalize = Normalize(v2);

	int kRowHeight = 20;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0 , 0 , resultAdd , "  : Add");
		VectorScreenPrintf(0 , kRowHeight , resultSubtract , "  : Subtract");
		VectorScreenPrintf(0 , kRowHeight * 2 , resultMultiply , "  : Multiply");
		Novice::ScreenPrintf(0 , kRowHeight * 3 , "%.02f  : Dot" , resultDot);
		Novice::ScreenPrintf(0 , kRowHeight * 4 , "%.02f  : Length" , resultLength);
		VectorScreenPrintf(0 , kRowHeight * 5 , resultNormalize , "  : Normalize");

		///
		/// ↑描画処理ここまで
		///

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
