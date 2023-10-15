#include "RSA_Class.hpp"

int main()
{
    // init an instance
    RSA instance;

    cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "选择加密(0)/解密(1): ";
    int choose;
    while(1)
	{
		cin >> choose;
		getchar();
		if((choose != 0) && (choose != 1))
			cout << "输入错误，重新输入0或1: ";
		else
			break;
	}

    if (choose == 0)
    {
        cout << "是否生成密钥:是(1)/否(0)? ";
        int choose2;
        while(1)
	    {
		    cin >> choose2;
		    getchar();
		    if((choose2 != 0) && (choose2 != 1))
			    cout << "输入错误，重新输入0或1: ";
		    else
			    break;
	    }


        // need to generate the key
        if (choose2 == 1)
        {
            instance.GenerateLargePrime();
            instance.KeyGeneration();
            cout << "密钥生成完毕，存储至当前目录key_e.txt、key_d.txt、key_n.txt。"  << endl << endl;

            cout << "请输入要加密的明文: ";
            string plaintextStr;
            getline(cin, plaintextStr);
            // plaintextStr = "this is the sentence that will be encrypt";
            // cout << plaintextStr;
            cout << endl;
            instance.AddPlainStrToHexPlaintext(plaintextStr);

            cout << "输入明文转换为16进制为: " << instance.hexPlaintext << endl << endl;
            cout << "加密密钥e为: " << instance.eChar << endl << endl;
            cout << "解密密钥d为: " << instance.dChar << endl << endl;
            cout << "加密密钥n为: " << instance.nChar << endl << endl;

            instance.RSA_Encrypt();
            cout << "加密密文为: " << instance.cipher << endl;
        }

        // don't need to generate the key
        if (choose2 == 0)
        {
            cout << "请输入要加密的明文: ";
            string plaintextStr;
            getline(cin, plaintextStr);
            // plaintextStr = "this is the sentence that will be encrypt";
            // cout << plaintextStr;
            cout << endl;
            instance.AddPlainStrToHexPlaintext(plaintextStr);
            
            cout << "请输入加密密钥e(16进制): ";
            string eStr;
            getline(cin, eStr);
            // eStr = "10001";
            // cout << eStr;
            cout << endl;

            cout << "请输入加密密钥n(16进制): ";
            string nStr;
            getline(cin, nStr);
            // nStr = "10ac0719d1b1502a43f68a5693744a44a2a9a833865e83332804d8ab7f7b4f25d4a98b459ddd86039ba5fe96a16b332ca15e1e7270cb17c0fd6529ddf3eb0c15180b3505b702087c30b093d57ab64dca18e6d5f44378323b11ab3c6011930a1b31cb98c77b56e74183eae32fb18823fb6a36e8dbba6f1c8f67d9fa857c3e10b0f296ffb192065c1bfbd6b8121bbbd2617e3fda09ada501fa1bb0e57ebbdc22ee7e47a72a90625257cc867d8eaded80e2f0294ea65312d0769f649bc29833433f079de73661ce59aedf4aa557320020e4d4923e3bb36a3195fd943f57e91c15c8c5f31490ed2640e1341291ff87eab56e337e644c5a59ba3fcc6def7a5a2e0bef";
            // cout << nStr;
            cout << endl;

            // store key to instance
            instance.AddHexStrToKey(nStr, eStr);

            cout << "输入明文转换为16进制为: " << instance.hexPlaintext << endl << endl;
            cout << "加密密钥e为: " << instance.eChar << endl << endl;
            cout << "加密密钥n为: " << instance.nChar << endl << endl;

            instance.RSA_Encrypt();
            cout << "加密密文为: " << instance.cipher << endl;
        }
    }

    if (choose == 1)
    {
        cout << "请输入要解密的密文: ";
        string cipherStr;
        getline(cin, cipherStr);
        // cipherStr = "54f1a90428c9bea54a053ba064adafe1f3ec1478b2b9fa6bc29b1c72de24ef2c4c15e2eb689ad72d57441340c9378beab483ddfc5c823f39dbef0bb20f65cf4d51e85e8263b9ed06825046631f24306e108d2e505f5dfa0e0b07665cc0dba8609bcc1554a8ab003390ee216dfb41d79fb6f614831a737d78c2317d1f624944e78c7924c308fe7ffd9713359aeb379b1b64bf6e716e4a6eba06f7a8c4b8b1c1be0ac8015d7acbe897be6bab89f00a2e15359fa02873c18fffc523a8f3b750b80ca7eae10cf119ef8b0b75e621fce976e42595c6419e89d8ffa93164bb3f3e44f0b489b3fa433e2ad0cc99150fb3b30d2ca83d398472a37426b71a40c481be0c6";
        // cout << cipherStr;
        cout << endl;
        instance.AddHexStrToCipher(cipherStr);
        
        cout << "请输入解密密钥d(16进制): ";
        string dStr;
        getline(cin, dStr);
        // dStr = "46fd0c94155eaa35853026d03b58fdf4f7ed3da59ad816b0710c15fb60f20476027a9ec6b2a074fe2accd89422569486b1c41ef78cd2999ccfb263aa4a23ce5909bd372855057578feaf348fac355f1e91b003dde8af375149ae58edb98da3bdea67a04f8af9ac56c2fbe22a3b191bf4249c72bcbff377899958729544de6db170c69a50761e11ecbb0a857f8f814bc085b7fb5053ecb9522d08ece6ca1f2a6b8d6795cfbdbdd27093cdc4a3073a17aef40237217fd433f044064583c7bddb92e520750f41758139df13b7f25ad8760011b931f0c6c45b847815f62e5544aaf890a5fc7ebc114d23b7df81c350db8b4dbbd53f1253be7e8f0ce834ab790cd1";
        // cout << dStr;
        cout << endl;

        cout << "请输入加密密钥n(16进制): ";
        string nStr;
        getline(cin, nStr);
        // nStr = "921e00a6fe9b65ca59d6ac628ede3ddc69c3325287506a12127f27f07d67fcb845dbbb928930f21870c7ae72b5791bc3d8770038f480f3c62f7681e7277a686ed3ab1a49ae8d13cc728ef2de8f17810f928363ae8a868f91e3b2102d6e56af0c34c9cc78c2116cf6dc6318bfa808eede4cce0451b5c64ca5d4053ddbe942877f3e83a9d9eb7cf5c086dd83957d0bdba0d77d67a84daf7944f86acee04985a5cb055d15a57c886a0a3ccbc1dd714d5e312202da52c99f678c486a1bb11a388a256fbb4c637d8b6b33ebcbb331a32fa9d7870a11fd797a9e4cf7a63c027d78d0968e94367a9a6cdf822fc1c12e03f5d9f4163490b372fd1082aaa6a3c6bac7fb7";
        // cout << nStr;
        cout << endl;

        // store key to instance
        instance.AddHexStrToKey(nStr, "", dStr);

        cout << "解密密钥d为: " << instance.dChar << endl << endl;
        cout << "解密密钥n为: " << instance.nChar << endl << endl;

        instance.RSA_Decrypt();
        cout << "解密16进制明文为: " << instance.hexPlaintext << endl << endl;
        cout << "解密明文为: " << instance.plaintext << endl;
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
    return 0; 
}