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
            // getline(cin, plaintextStr);
            plaintextStr = "this is the sentence that will be encrypt";
            cout << plaintextStr;
            cout << endl << endl;
            instance.AddPlainStrToHexPlaintext(plaintextStr);

            cout << "输入明文转换为16进制为: " << instance.plaintext << endl << endl;
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
            // getline(cin, plaintextStr);
            plaintextStr = "this is the sentence that will be encrypt";
            cout << plaintextStr;
            cout << endl << endl;
            instance.AddPlainStrToHexPlaintext(plaintextStr);
            
            cout << "请输入加密密钥e(16进制): ";
            string eStr;
            // getline(cin, eStr);
            eStr = "10001";
            cout << eStr;
            cout << endl << endl;

            cout << "请输入加密密钥n(16进制): ";
            string nStr;
            // getline(cin, nStr);
            nStr = "10ac0719d1b1502a43f68a5693744a44a2a9a833865e83332804d8ab7f7b4f25d4a98b459ddd86039ba5fe96a16b332ca15e1e7270cb17c0fd6529ddf3eb0c15180b3505b702087c30b093d57ab64dca18e6d5f44378323b11ab3c6011930a1b31cb98c77b56e74183eae32fb18823fb6a36e8dbba6f1c8f67d9fa857c3e10b0f296ffb192065c1bfbd6b8121bbbd2617e3fda09ada501fa1bb0e57ebbdc22ee7e47a72a90625257cc867d8eaded80e2f0294ea65312d0769f649bc29833433f079de73661ce59aedf4aa557320020e4d4923e3bb36a3195fd943f57e91c15c8c5f31490ed2640e1341291ff87eab56e337e644c5a59ba3fcc6def7a5a2e0bef";
            cout << nStr;
            cout << endl << endl;

            // store key to instance
            instance.AddHexStrToKey(nStr, eStr);

            cout << "输入明文转换为16进制为: " << instance.plaintext << endl << endl;
            cout << "加密密钥e为: " << instance.eChar << endl << endl;
            cout << "加密密钥n为: " << instance.nChar << endl << endl;

            instance.RSA_Encrypt();
            cout << "加密密文为: " << instance.cipher << endl;
        }
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
    return 0; 
}

