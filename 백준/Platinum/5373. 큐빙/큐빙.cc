#include <bits/stdc++.h>

using namespace std;

int n;

void initCube(map<char, char[3][3]>& cube) {
    vector<char> colors = {'w', 'y', 'r', 'o', 'g', 'b'};
    vector<char> faces = {'U', 'D', 'F', 'B', 'L', 'R'};

    for (int f=0;f<6;f++) {
        char face = faces[f];
        char color = colors[f];

        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                cube[face][i][j] = color;
            }
        }
    }
}

void rotateFace(char face[3][3], char dir) {
    char tmp[3][3];

    // 시계 방향
    if (dir == '+') {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                tmp[j][2 - i] = face[i][j];
            }
        }
    }
    // 반시계 방향
    else {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                tmp[2 - j][i] = face[i][j];
            }
        }
    }

    memcpy(face, tmp, sizeof(tmp));
}

void rotateU(map<char, char[3][3]>& cube, char dir) {
    rotateFace(cube['U'], dir);
    char temp[3];

    if (dir == '+') {
        for (int i = 0; i < 3; i++) temp[i] = cube['F'][0][i];
        for (int i = 0; i < 3; i++) cube['F'][0][i] = cube['R'][0][i];
        for (int i = 0; i < 3; i++) cube['R'][0][i] = cube['B'][0][i];
        for (int i = 0; i < 3; i++) cube['B'][0][i] = cube['L'][0][i];
        for (int i = 0; i < 3; i++) cube['L'][0][i] = temp[i];
    } else {
        for (int i = 0; i < 3; i++) temp[i] = cube['F'][0][i];
        for (int i = 0; i < 3; i++) cube['F'][0][i] = cube['L'][0][i];
        for (int i = 0; i < 3; i++) cube['L'][0][i] = cube['B'][0][i];
        for (int i = 0; i < 3; i++) cube['B'][0][i] = cube['R'][0][i];
        for (int i = 0; i < 3; i++) cube['R'][0][i] = temp[i];
    }
}

void rotateD(map<char, char[3][3]>& cube, char dir) {
    rotateFace(cube['D'], dir);
    char temp[3];

    if (dir == '+') {
        for (int i = 0; i < 3; i++) temp[i] = cube['F'][2][i];
        for (int i = 0; i < 3; i++) cube['F'][2][i] = cube['L'][2][i];
        for (int i = 0; i < 3; i++) cube['L'][2][i] = cube['B'][2][i];
        for (int i = 0; i < 3; i++) cube['B'][2][i] = cube['R'][2][i];
        for (int i = 0; i < 3; i++) cube['R'][2][i] = temp[i];
    } else {
        for (int i = 0; i < 3; i++) temp[i] = cube['F'][2][i];
        for (int i = 0; i < 3; i++) cube['F'][2][i] = cube['R'][2][i];
        for (int i = 0; i < 3; i++) cube['R'][2][i] = cube['B'][2][i];
        for (int i = 0; i < 3; i++) cube['B'][2][i] = cube['L'][2][i];
        for (int i = 0; i < 3; i++) cube['L'][2][i] = temp[i];
    }
}

void rotateF(map<char, char[3][3]>& cube, char dir) {
    rotateFace(cube['F'], dir);
    char temp[3];

    if (dir == '+') {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][2][i];
        for (int i = 0; i < 3; i++) cube['U'][2][i] = cube['L'][2 - i][2];
        for (int i = 0; i < 3; i++) cube['L'][i][2] = cube['D'][0][i];
        for (int i = 0; i < 3; i++) cube['D'][0][i] = cube['R'][2 - i][0];
        for (int i = 0; i < 3; i++) cube['R'][i][0] = temp[i];
    } else {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][2][i];
        for (int i = 0; i < 3; i++) cube['U'][2][i] = cube['R'][i][0];
        for (int i = 0; i < 3; i++) cube['R'][i][0] = cube['D'][0][2 - i];
        for (int i = 0; i < 3; i++) cube['D'][0][i] = cube['L'][i][2];
        for (int i = 0; i < 3; i++) cube['L'][i][2] = temp[2 - i];
    }
}

void rotateB(map<char, char[3][3]>& cube, char dir) {
    rotateFace(cube['B'], dir);
    char temp[3];

    if (dir == '+') {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][0][i];
        for (int i = 0; i < 3; i++) cube['U'][0][i] = cube['R'][i][2];
        for (int i = 0; i < 3; i++) cube['R'][i][2] = cube['D'][2][2 - i];
        for (int i = 0; i < 3; i++) cube['D'][2][i] = cube['L'][i][0];
        for (int i = 0; i < 3; i++) cube['L'][i][0] = temp[2 - i];
    } else {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][0][i];
        for (int i = 0; i < 3; i++) cube['U'][0][i] = cube['L'][2 - i][0];
        for (int i = 0; i < 3; i++) cube['L'][i][0] = cube['D'][2][i];
        for (int i = 0; i < 3; i++) cube['D'][2][i] = cube['R'][2 - i][2];
        for (int i = 0; i < 3; i++) cube['R'][i][2] = temp[i];
    }
}

void rotateL(map<char, char[3][3]>& cube, char dir) {
    rotateFace(cube['L'], dir);
    char temp[3];

    if (dir == '+') {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][i][0];
        for (int i = 0; i < 3; i++) cube['U'][i][0] = cube['B'][2 - i][2];
        for (int i = 0; i < 3; i++) cube['B'][i][2] = cube['D'][2 - i][0];
        for (int i = 0; i < 3; i++) cube['D'][i][0] = cube['F'][i][0];
        for (int i = 0; i < 3; i++) cube['F'][i][0] = temp[i];
    } else {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][i][0];
        for (int i = 0; i < 3; i++) cube['U'][i][0] = cube['F'][i][0];
        for (int i = 0; i < 3; i++) cube['F'][i][0] = cube['D'][i][0];
        for (int i = 0; i < 3; i++) cube['D'][i][0] = cube['B'][2 - i][2];
        for (int i = 0; i < 3; i++) cube['B'][i][2] = temp[2 - i];
    }
}

void rotateR(map<char, char[3][3]>& cube, char dir) {
    rotateFace(cube['R'], dir);
    char temp[3];

    if (dir == '+') {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][i][2];
        for (int i = 0; i < 3; i++) cube['U'][i][2] = cube['F'][i][2];
        for (int i = 0; i < 3; i++) cube['F'][i][2] = cube['D'][i][2];
        for (int i = 0; i < 3; i++) cube['D'][i][2] = cube['B'][2 - i][0];
        for (int i = 0; i < 3; i++) cube['B'][i][0] = temp[2 - i];
    } else {
        for (int i = 0; i < 3; i++) temp[i] = cube['U'][i][2];
        for (int i = 0; i < 3; i++) cube['U'][i][2] = cube['B'][2 - i][0];
        for (int i = 0; i < 3; i++) cube['B'][i][0] = cube['D'][2 - i][2];
        for (int i = 0; i < 3; i++) cube['D'][i][2] = cube['F'][i][2];
        for (int i = 0; i < 3; i++) cube['F'][i][2] = temp[i];
    }
}


void rotate(map<char, char[3][3]>& cube, char face, char dir) {
    if (face == 'U') rotateU(cube, dir);
    if (face == 'D') rotateD(cube, dir);
    if (face == 'F') rotateF(cube, dir);
    if (face == 'B') rotateB(cube, dir);
    if (face == 'L') rotateL(cube, dir);
    if (face == 'R') rotateR(cube, dir);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        // 큐브 초기화
        map<char, char[3][3]> cube;
        initCube(cube);

        // 명령어 입력
        cin >> n;

        for (int i=0;i<n;i++) {
            string str;
            cin >> str;

            rotate(cube, str[0], str[1]);
        }

        // 윗 면 출력
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                cout << cube['U'][i][j];
            }
            cout << "\n";
        }
    }

}
