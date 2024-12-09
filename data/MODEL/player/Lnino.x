xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 48;
 0.00000;0.00000;1.25600;,
 -0.00032;-0.79422;0.92407;,
 0.88534;-1.56892;1.70766;,
 0.88606;-0.00020;2.36401;,
 -0.00118;-1.12313;0.12195;,
 0.88365;-2.21855;0.12330;,
 -0.00206;-0.79399;-0.68037;,
 0.88192;-1.56845;-1.46137;,
 -0.00238;0.00041;-1.01233;,
 0.88126;0.00047;-2.11728;,
 -0.00205;0.79461;-0.68027;,
 0.88193;1.56928;-1.46118;,
 -0.00118;1.12349;0.12197;,
 0.88364;2.21889;0.12321;,
 -0.00031;0.79436;0.92417;,
 0.88534;1.56881;1.70760;,
 2.21014;-2.08659;2.23264;,
 2.21103;-0.00026;3.10496;,
 2.20786;-2.95051;0.12528;,
 2.20560;-2.08597;-1.98167;,
 2.20466;0.00058;-2.85448;,
 2.20560;2.08688;-1.98166;,
 2.20787;2.95079;0.12539;,
 2.21011;2.08625;2.23224;,
 3.77234;-2.26840;2.41847;,
 3.77334;-0.00037;3.36706;,
 3.76988;-3.20755;0.12780;,
 3.76744;-2.26772;-2.16274;,
 3.76644;0.00058;-3.11138;,
 3.76744;2.26861;-2.16273;,
 3.76990;3.20776;0.12793;,
 3.77234;2.26792;2.41837;,
 10.65989;-1.01768;1.15053;,
 10.65989;0.00350;1.57352;,
 10.65989;-1.44067;0.12935;,
 10.65989;-1.01768;-0.89184;,
 10.65989;0.00350;-1.31482;,
 10.65989;1.02469;-0.89184;,
 10.65989;1.44768;0.12935;,
 10.65989;1.02469;1.15053;,
 11.54912;-0.58429;0.71714;,
 11.54912;0.00350;0.96061;,
 11.54912;-0.82775;0.12935;,
 11.54912;-0.58429;-0.45844;,
 11.54912;0.00350;-0.70191;,
 11.54912;0.59131;-0.45844;,
 11.54912;0.83478;0.12935;,
 11.54912;0.59131;0.71714;;
 
 46;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 4;3,2,16,17;,
 4;2,5,18,16;,
 4;5,7,19,18;,
 4;7,9,20,19;,
 4;9,11,21,20;,
 4;11,13,22,21;,
 4;13,15,23,22;,
 4;15,3,17,23;,
 4;17,16,24,25;,
 4;16,18,26,24;,
 4;18,19,27,26;,
 4;19,20,28,27;,
 4;20,21,29,28;,
 4;21,22,30,29;,
 4;22,23,31,30;,
 4;23,17,25,31;,
 4;25,24,32,33;,
 4;24,26,34,32;,
 4;26,27,35,34;,
 4;27,28,36,35;,
 4;28,29,37,36;,
 4;29,30,38,37;,
 4;30,31,39,38;,
 4;31,25,33,39;,
 4;33,32,40,41;,
 4;32,34,42,40;,
 4;34,35,43,42;,
 4;35,36,44,43;,
 4;36,37,45,44;,
 4;37,38,46,45;,
 4;38,39,47,46;,
 4;39,33,41,47;,
 4;43,44,45,46;,
 4;46,47,42,43;,
 4;41,40,42,47;,
 4;14,12,10,8;,
 4;8,6,0,14;,
 4;6,4,1,0;;
 
 MeshMaterialList {
  2;
  46;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.473726;0.586667;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  48;
  -0.945356;-0.000003;0.326040;,
  -0.900224;-0.308789;0.306994;,
  -0.899576;-0.436763;0.000845;,
  -0.945273;-0.232136;-0.229286;,
  -0.945729;0.000028;-0.324955;,
  -0.900467;0.309296;-0.305771;,
  -0.899582;0.436750;0.000954;,
  -0.944994;0.231770;0.230801;,
  -0.648757;0.000015;0.760996;,
  -0.646972;-0.541075;0.537275;,
  -0.644926;-0.764245;0.000467;,
  -0.646435;-0.541855;-0.537136;,
  -0.648091;0.000042;-0.761563;,
  -0.646471;0.541928;-0.537019;,
  -0.644905;0.764262;0.000666;,
  -0.646858;0.541064;0.537424;,
  -0.333001;0.000032;0.942926;,
  -0.331316;-0.669492;0.664838;,
  -0.329081;-0.944302;0.000115;,
  -0.329607;-0.670073;-0.665103;,
  -0.330660;0.000029;-0.943750;,
  -0.329628;0.670177;-0.664988;,
  -0.329049;0.944313;0.000381;,
  -0.331239;0.669429;0.664940;,
  0.044495;0.000025;0.999010;,
  0.044389;-0.708327;0.704487;,
  0.044474;-0.999010;-0.000109;,
  0.045426;-0.708223;-0.704526;,
  0.045980;0.000025;-0.998942;,
  0.045130;0.708325;-0.704442;,
  0.043931;0.999035;0.000120;,
  0.043933;0.708286;0.704557;,
  0.417566;0.000007;0.908646;,
  0.416933;-0.643394;0.642036;,
  0.416194;-0.909276;-0.000089;,
  0.416884;-0.643324;-0.642139;,
  0.417497;0.000011;-0.908678;,
  0.416614;0.643445;-0.642193;,
  0.415694;0.909505;-0.000010;,
  0.416527;0.643512;0.642182;,
  0.799466;-0.000002;0.600712;,
  0.799467;-0.424768;0.424765;,
  0.891924;-0.452185;0.000001;,
  0.891926;-0.319742;-0.319740;,
  0.799467;-0.000002;-0.600711;,
  0.799466;0.424765;-0.424769;,
  0.891923;0.452188;0.000001;,
  0.891923;0.319743;0.319745;;
  46;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  4;24,25,33,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,24,32,39;,
  4;32,33,41,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,32,40,47;,
  4;43,44,45,46;,
  4;46,47,42,43;,
  4;40,41,42,47;,
  4;7,6,5,4;,
  4;4,3,0,7;,
  4;3,2,1,0;;
 }
 MeshTextureCoords {
  48;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
