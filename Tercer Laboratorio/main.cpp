///#include <iostream>
///using namespace std;
#include "Affin.h"
#include "Func.h"


int main()
{
    cout << "Hello world!" << endl;
    ///string mensaje= "In my eyes indisposed In disguises no one knows Hides the face lies the snake The sun in my disgrace Boiling heat summer stench Neath the black the sky looks dead Call my name through the cream And Ill hear you scream again Patrick Xavier Marquez Choque 161-10-37243";
    ///string mensaje = "Tonight youre falling in love Let me go now This feelings tearing me up Here we go now Now if she does it like this Will you do it like that Now if she touches like this Will you touch her like that Now if she moves like this Will you move her like that Come on shake shake Shake shake shake it Patrick Xavier Marquez Choque 161-10-37243 me siento productivo dos puntos ube";
    string mensaje = "Warm sun feed me up Im leery loaded up Loathing for a change And I slip some Boil away Swallowed followed Heavy about everything but my love Swallowed sorrowed Im with everyone and yet not Im with everyone and yet not Im with everyone and yet not Just wanted to be myself Hey you said you would love to try some Hey you said you would love to die some In the middle of a world on a fishhook Youre the wave Youre the wave Youre the wave Swallowed borrowed Heavy about everything but my love Swallowed hollowed Sharp about everyone but yourself Swallowed oh no Im with everyone and yet not Im with everyone and yet not Im with everyone and you're not I'm with everyone and yet Piss on self esteem Forward busted knee Sick head Blackened lungs And Im a simple selfish son Swallowed followed Heavy about everything but my love Swallowed oh no Im with everyone and yet not Im with everyone and yet not Im with everyone and yet not Got to get away from here Got to get away from here Got to get away from here Got to get away from here I miss the one that I love a lot I miss the one that I love a lot I miss the one that I love a lot I love Patrick Xavier Marquez Choque 161-10-37243";
    ///string mensaje ="Ella nunca te amo .v";
    ///string mensaje_encriptado="cDxGAWIAWQLWiKQWGJKSWEIWFQOPWxWHEPPHAWQJ KJAWgxGAWIAWQLWZxQOAWARANUWyEPWKBWIAWDxOWCKJAWJQIyW6ECDPWDxRAWzQPWIUWBEJCANW6ECDPWDxRAWzQPWIUWOKQHW6ECDPWDxRAWyAAJWxWPDEJGANWSDAJWEWPDKQCDPWEWDx WzKJPNKHW1KSWEIWCKJJxWBECQNAWgDANAWEIWCKJJxWCKW-KQJ WIUOAHBWxWNERANWxJ WEHHWOEJGWQJPEHWEWBHKSW1QNPWIxzDEJAOWYACEJWPKWBAA WgDAJWEWHAPWPDAW AIKJOWNE AW_JPANWIUW NAxIOWgDANAW xNGJAOOWOEJCOWgDAJWEWHAPWPDAW AIKJOWNE AW6AOOWIAWQLW2IWSxHGEJCWSEPDWIUWBAAPWEJWPDAWIQzGW-ETWIAWQLWiKQNAWPxHGEJCWHEGAWUKQWGJKSWSDANAWEIWBNKIW5KKGWEJPKWPDAWODx KSOW5KKGWEJPKWIUWDKIAW5KKGWEJPKWPDAWBENAWSDANAWUKQHHWBEJ WIAWxHHWxHKJAWbQJJEJCWPKWPDAWIAx KSOW1E EJCWBNKIWPDAWCDKOPW7KSWEIWOAAEJCWyK EAOWSDANAWEWQOA WPKWOAAWPDAWOIKGAW1QNPWIxzDEJAOWYACEJWPKWBAA WgDAJWEWHAPWPDAW AIKJOWNE AW_JPANWIUW NAxIOWgDANAW xNGJAOOWOEJCOWgDAJWEWHAPWPDAW AIKJOWNE AWcEHAJzAWxJ WODx KSOWfEKHAPWPNAAWIAx KSOWcEHAJzAWxJ WODx KSOWfEKHAJPWPNAAWIAx KSOW1QNPWIxzDEJAOWYACEJWPKWBAA WgDAJWEWHAPWPDAW AIKJOWNE AW_JPANWIUW NAxIOWgDANAW xNGJAOOWOEJCOWgDAJWEWHAPWPDAW AIKJOWNE AWb2._Wb2._Wb2._Wb2._Wb2._W._687cWb2._W3AxJWZxNHKWZKNJAFKWZKNJAFKWotomonmqtrtq";
    ///string mensaje_encriptado="5Nn8MLWWXNisjN4dLjNXHe9sNGssMNoLX8MiNJH4NjdLjN4stsN_MssNxssCNo8xsNGXNo8xsNgdsNojHtRNBWHexoNLtsNB8tBW8MiNLGH9sNeoNIoN4sNojteiiWsNLiL8MojNjdsNj8xsN5NnssWNXHetNit8CNn8tRNHMNRXNodHeWxstNDejNjd8oNnsLtN8MNRXNdsLxN4HMjNoeGo8xsNgdsXNCLj8sMjWXNB8tBWsNLtHeMxNeoNIoN4sNdHWxNHejNEdNnLjdstN4dXNdL9sNjdsXNnHtoL_sMNRsNUHeN4LtMsxNRsNjdLjNjdsXN4HeWxNDsBLeosN8joNCLoo8MiNxH4MNjdsNGWHHxW8MsN5joNoCH_sMNLMxNR8oeMxstojHHxN1stsNWHo8MiNW8idjNIMxNojtsMijdNHnN48WWNgdsNxLt_sMsxNxsCjdoNGsB_HM8MiNoj8WWNIMxN4sNdHWxNHMNLiL8MojNjdsNj8xsNDsMsLjdNjdsNojHtRNXHetsNWsnjNjHNn8idjNLWHMsNqsRsRGstNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNbMxstNjdsN4L9soNLMxNo8M_8MiNW8_sNLNojHMsN5RNoHttXNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNNDsMsLjdNjdsNojHtRNXHetsNWsnjNjHNn8idjNLWHMsNqsRsRGstNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNbMxstNjdsN4L9soNLMxNo8M_8MiNW8_sNLNojHMsN5RNoHttXNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MN1stsNoWH4WXNWHo8MiNitHeMxNIMxNdHCsN8oNdLtxstNjHNRL8MjL8MN1dsMNLWWNjdsNCtLXstoN4sNCtLXsxNkssWNWHojNW8_sNjsLtoN8MNjdsNtL8MNgdsN4LjstoNCeWW8MiNxH4MNgdsNRHHMoNsBW8Co8MiNjdsNoeMNgdsNsMx8MiNjdLjN4sN_Ms4N4HeWxNBHRsNaLoNn8MLWWXNGsieMNUHetsNtsLC8MiN4dLjNXHe9sNoH4MN5joNn8MLWWXNGsieMNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MN5RNoHttXNoHMNXHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNUHetsNtsLC8MiN4dLjNXHe9sNoH4MNgd8oNoHttH4N4s8idoNxH4MNHMNRXNodHeWxstoNgd8oNnsLtoNisjj8MiNdLtxstNjHNd8xsNUHeWWNWsL9sNRsNLWHMsN8MNjd8oNxLt_MsooNTsnjNjHNdHWxNHejNIiL8MojNjdsNj8xs";
    ///cout <<mensaje.size()<<" - "<<mensaje.length()<<endl;
    ///Affin Encrip(25537,38);
    Affin Encrip;
    string mensaje_encriptado = Encrip.Affin_Encriptacion(mensaje);
    cout <<Encrip.Affin_Encriptacion(mensaje)<<endl;

    cout <<Encrip.Affin_Desencriptacion(mensaje_encriptado)<<endl;


    return 0;
}
