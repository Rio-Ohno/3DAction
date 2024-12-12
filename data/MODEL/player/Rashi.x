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
 79;
 0.78500;-4.50000;-5.00000;,
 -0.04551;-4.50586;-4.98959;,
 0.06675;-0.83861;-0.97577;,
 0.64670;-0.83548;-0.96838;,
 0.64670;-0.83548;-0.96838;,
 0.06675;-0.83861;-0.97577;,
 0.05644;-0.33344;-0.38109;,
 0.63638;-0.33031;-0.37369;,
 0.04568;-0.09432;0.36166;,
 0.62562;-0.09119;0.36905;,
 0.03609;-0.15766;1.13939;,
 0.61604;-0.15453;1.14679;,
 0.04998;-0.55504;1.53957;,
 0.59624;-0.55209;1.54654;,
 0.07202;-1.22152;1.73674;,
 0.57637;-1.21880;1.74317;,
 0.77507;-4.74731;-6.80707;,
 -0.05544;-4.75317;-6.79666;,
 -0.04551;-4.50586;-4.98959;,
 0.77029;-5.16868;-7.91751;,
 -0.06021;-5.17453;-7.90710;,
 0.77138;-5.84520;-8.66886;,
 -0.05912;-5.85105;-8.65845;,
 0.75493;-6.46700;-8.57642;,
 -0.02733;-6.47251;-8.56662;,
 0.73787;-7.12645;-7.91314;,
 0.01561;-7.13154;-7.90409;,
 -1.13962;-4.68101;-4.97982;,
 -0.69955;-0.93731;-0.86624;,
 -2.06352;-5.16434;-4.97947;,
 -1.35122;-1.21015;-0.53478;,
 -2.67657;-5.88227;-4.98859;,
 -1.78903;-1.61556;-0.03187;,
 -2.69584;-6.50717;-4.83506;,
 -1.81075;-2.04139;0.34546;,
 -2.26068;-7.13975;-4.64656;,
 -1.51522;-2.48939;0.71814;,
 1.41098;-0.92592;-0.83932;,
 1.88276;-4.65970;-5.01770;,
 2.05688;-1.19175;-0.49131;,
 2.81703;-5.12993;-5.04065;,
 2.48607;-1.59249;0.02266;,
 3.44558;-5.83910;-5.06534;,
 2.50276;-2.01811;0.40048;,
 3.48130;-6.46361;-4.91249;,
 2.20267;-2.46933;0.76557;,
 3.06350;-7.10221;-4.71330;,
 -0.94919;-0.42429;0.09162;,
 -1.55273;-0.89026;0.54513;,
 -0.88469;-0.35663;0.97384;,
 -1.67612;-1.47571;0.79506;,
 -1.27524;-0.99459;1.17987;,
 -0.66911;-0.67130;1.44130;,
 1.63056;-0.41037;0.12453;,
 2.22732;-0.86986;0.59335;,
 1.54284;-0.34353;1.00480;,
 2.35061;-1.45398;0.84643;,
 1.93487;-0.97727;1.22082;,
 1.31881;-0.66057;1.46667;,
 -1.30972;-1.85863;1.21993;,
 -0.72875;-1.39455;1.59277;,
 -1.48576;-5.22000;-7.18748;,
 -2.33628;-5.94612;-7.06466;,
 -1.37824;-5.88153;-8.22251;,
 -2.50158;-6.58941;-6.56541;,
 -1.92624;-6.53308;-7.60804;,
 -1.05740;-6.49204;-8.31077;,
 1.97764;-1.84089;1.26187;,
 1.38238;-1.38316;1.61970;,
 -1.96475;-7.21421;-6.51806;,
 -1.13158;-7.15804;-7.52499;,
 2.20856;-5.19396;-7.23378;,
 3.07692;-5.90796;-7.13252;,
 2.09810;-5.85702;-8.26608;,
 3.26490;-6.54875;-6.63770;,
 2.67079;-6.50068;-7.66566;,
 1.78940;-6.47197;-8.34645;,
 2.74290;-7.18102;-6.57707;,
 1.89165;-7.13673;-7.56288;;
 
 120;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;16,17,18,0;,
 4;19,20,17,16;,
 4;21,22,20,19;,
 4;23,24,22,21;,
 4;25,26,24,23;,
 4;5,18,27,28;,
 4;28,27,29,30;,
 4;30,29,31,32;,
 4;32,31,33,34;,
 4;35,36,34,33;,
 4;0,4,37,38;,
 4;38,37,39,40;,
 4;40,39,41,42;,
 4;42,41,43,44;,
 4;45,46,44,43;,
 3;5,28,6;,
 3;28,30,47;,
 3;47,6,28;,
 3;6,47,8;,
 3;30,32,48;,
 3;48,47,30;,
 3;47,48,49;,
 3;49,8,47;,
 3;8,49,10;,
 3;32,34,50;,
 3;50,48,32;,
 3;48,50,51;,
 3;51,49,48;,
 3;49,51,52;,
 3;52,10,49;,
 3;10,52,12;,
 3;7,37,4;,
 3;53,39,37;,
 3;37,7,53;,
 3;9,53,7;,
 3;54,41,39;,
 3;39,53,54;,
 3;55,54,53;,
 3;53,9,55;,
 3;11,55,9;,
 3;56,43,41;,
 3;41,54,56;,
 3;57,56,54;,
 3;54,55,57;,
 3;58,57,55;,
 3;55,11,58;,
 3;13,58,11;,
 3;50,34,36;,
 3;36,59,50;,
 3;51,50,59;,
 3;59,60,51;,
 3;52,51,60;,
 3;60,14,52;,
 3;12,52,14;,
 3;17,27,18;,
 3;61,29,27;,
 3;27,17,61;,
 3;20,61,17;,
 3;62,31,29;,
 3;29,61,62;,
 3;63,62,61;,
 3;61,20,63;,
 3;22,63,20;,
 3;64,33,31;,
 3;31,62,64;,
 3;65,64,62;,
 3;62,63,65;,
 3;66,65,63;,
 3;63,22,66;,
 3;24,66,22;,
 3;45,43,56;,
 3;56,67,45;,
 3;67,56,57;,
 3;57,68,67;,
 3;68,57,58;,
 3;58,15,68;,
 3;15,58,13;,
 3;35,33,64;,
 3;64,69,35;,
 3;69,64,65;,
 3;65,70,69;,
 3;70,65,66;,
 3;66,26,70;,
 3;26,66,24;,
 3;0,38,16;,
 3;38,40,71;,
 3;71,16,38;,
 3;16,71,19;,
 3;40,42,72;,
 3;72,71,40;,
 3;71,72,73;,
 3;73,19,71;,
 3;19,73,21;,
 3;42,44,74;,
 3;74,72,42;,
 3;72,74,75;,
 3;75,73,72;,
 3;73,75,76;,
 3;76,21,73;,
 3;21,76,23;,
 3;74,44,46;,
 3;46,77,74;,
 3;75,74,77;,
 3;77,78,75;,
 3;76,75,78;,
 3;78,25,76;,
 3;23,76,25;,
 4;35,46,45,36;,
 4;35,69,77,46;,
 4;70,78,77,69;,
 4;26,25,78,70;,
 4;45,67,59,36;,
 4;67,68,60,59;,
 4;68,15,14,60;;
 
 MeshMaterialList {
  2;
  120;
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
  77;
  0.072125;0.904712;-0.419874;,
  -0.085884;0.903264;-0.420402;,
  0.086064;0.750414;-0.655340;,
  -0.086359;0.748645;-0.657323;,
  0.077967;0.507994;0.857825;,
  -0.105306;0.507006;0.855485;,
  0.092532;-0.451771;-0.887322;,
  -0.108153;-0.453523;-0.884658;,
  -0.971171;-0.219936;0.091947;,
  -0.955238;-0.071387;0.287096;,
  0.975150;-0.204291;0.085716;,
  0.952048;-0.060894;0.299826;,
  0.151149;0.859410;-0.488435;,
  -0.147908;0.857795;-0.492251;,
  0.147296;0.984144;-0.098812;,
  -0.155339;0.982511;-0.102672;,
  0.131857;0.874669;0.466442;,
  -0.153145;0.873128;0.462810;,
  0.086547;0.042888;0.995324;,
  -0.112369;0.041820;0.992786;,
  0.109489;0.965495;-0.236288;,
  -0.129089;0.963478;-0.234618;,
  0.129440;0.841504;-0.524516;,
  -0.154483;0.838675;-0.522264;,
  0.154066;0.259752;-0.953306;,
  -0.181287;0.256132;-0.949490;,
  0.090628;-0.828384;-0.552781;,
  -0.092586;-0.829663;-0.550533;,
  -0.311654;0.882538;-0.352136;,
  -0.336212;0.740034;-0.582504;,
  -0.634530;0.718371;-0.285158;,
  -0.668788;0.617915;-0.413404;,
  -0.944109;0.297373;-0.142225;,
  -0.944320;0.320522;-0.074328;,
  -0.679928;-0.728085;0.087121;,
  -0.699010;-0.360503;0.617595;,
  0.297089;0.887595;-0.352013;,
  0.336791;0.745496;-0.575158;,
  0.621412;0.729143;-0.286701;,
  0.668583;0.627181;-0.399551;,
  0.937524;0.315060;-0.147598;,
  0.941630;0.331790;-0.056986;,
  0.691703;-0.717702;0.080317;,
  0.691256;-0.353764;0.630092;,
  -0.333711;0.468160;0.818207;,
  -0.678740;0.315429;0.663186;,
  -0.909171;0.080899;0.408489;,
  -0.351278;-0.445250;-0.823624;,
  -0.690698;-0.408961;-0.596395;,
  -0.911425;-0.335941;-0.237590;,
  0.307661;0.471622;0.826388;,
  0.658160;0.322647;0.680239;,
  0.897530;0.090653;0.431533;,
  0.338168;-0.439151;-0.832339;,
  0.685025;-0.396110;-0.611423;,
  0.914082;-0.317263;-0.252581;,
  -0.472979;0.829882;-0.295951;,
  -0.833463;0.550187;0.051330;,
  -0.484742;0.821786;0.299487;,
  0.471392;0.834978;-0.283903;,
  0.825896;0.559142;0.072498;,
  0.468050;0.826929;0.311638;,
  -0.485232;-0.294192;0.823408;,
  -0.289649;-0.168192;0.942239;,
  -0.427387;0.844339;-0.323161;,
  -0.846318;0.371778;-0.381481;,
  -0.535876;0.371376;-0.758233;,
  0.467215;-0.289050;0.835560;,
  0.267319;-0.165190;0.949343;,
  -0.426131;-0.878639;-0.215423;,
  -0.248657;-0.886277;-0.390747;,
  0.406533;0.852238;-0.329272;,
  0.831714;0.389902;-0.395257;,
  0.512555;0.382681;-0.768663;,
  0.435519;-0.871974;-0.223573;,
  0.252392;-0.882663;-0.396491;,
  0.004600;-0.758944;0.651140;;
  120;
  4;0,1,3,2;,
  4;2,3,13,12;,
  4;12,13,15,14;,
  4;14,15,17,16;,
  4;16,17,5,4;,
  4;4,5,19,18;,
  4;20,21,1,0;,
  4;22,23,21,20;,
  4;24,25,23,22;,
  4;6,7,25,24;,
  4;26,27,7,6;,
  4;3,1,28,29;,
  4;29,28,30,31;,
  4;31,30,32,33;,
  4;33,32,8,9;,
  4;34,35,9,8;,
  4;0,2,37,36;,
  4;36,37,39,38;,
  4;38,39,41,40;,
  4;40,41,11,10;,
  4;43,42,10,11;,
  3;3,29,13;,
  3;29,31,56;,
  3;56,13,29;,
  3;13,56,15;,
  3;31,33,57;,
  3;57,56,31;,
  3;56,57,58;,
  3;58,15,56;,
  3;15,58,17;,
  3;33,9,46;,
  3;46,57,33;,
  3;57,46,45;,
  3;45,58,57;,
  3;58,45,44;,
  3;44,17,58;,
  3;17,44,5;,
  3;12,37,2;,
  3;59,39,37;,
  3;37,12,59;,
  3;14,59,12;,
  3;60,41,39;,
  3;39,59,60;,
  3;61,60,59;,
  3;59,14,61;,
  3;16,61,14;,
  3;52,11,41;,
  3;41,60,52;,
  3;51,52,60;,
  3;60,61,51;,
  3;50,51,61;,
  3;61,16,50;,
  3;4,50,16;,
  3;46,9,35;,
  3;35,62,46;,
  3;45,46,62;,
  3;62,63,45;,
  3;44,45,63;,
  3;63,19,44;,
  3;5,44,19;,
  3;21,28,1;,
  3;64,30,28;,
  3;28,21,64;,
  3;23,64,21;,
  3;65,32,30;,
  3;30,64,65;,
  3;66,65,64;,
  3;64,23,66;,
  3;25,66,23;,
  3;49,8,32;,
  3;32,65,49;,
  3;48,49,65;,
  3;65,66,48;,
  3;47,48,66;,
  3;66,25,47;,
  3;7,47,25;,
  3;43,11,52;,
  3;52,67,43;,
  3;67,52,51;,
  3;51,68,67;,
  3;68,51,50;,
  3;50,18,68;,
  3;18,50,4;,
  3;34,8,49;,
  3;49,69,34;,
  3;69,49,48;,
  3;48,70,69;,
  3;70,48,47;,
  3;47,27,70;,
  3;27,47,7;,
  3;0,36,20;,
  3;36,38,71;,
  3;71,20,36;,
  3;20,71,22;,
  3;38,40,72;,
  3;72,71,38;,
  3;71,72,73;,
  3;73,22,71;,
  3;22,73,24;,
  3;40,10,55;,
  3;55,72,40;,
  3;72,55,54;,
  3;54,73,72;,
  3;73,54,53;,
  3;53,24,73;,
  3;24,53,6;,
  3;55,10,42;,
  3;42,74,55;,
  3;54,55,74;,
  3;74,75,54;,
  3;53,54,75;,
  3;75,26,53;,
  3;6,53,26;,
  4;76,76,76,76;,
  4;34,69,74,42;,
  4;70,75,74,69;,
  4;27,26,75,70;,
  4;43,67,62,35;,
  4;67,68,63,62;,
  4;68,18,19,63;;
 }
 MeshTextureCoords {
  79;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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