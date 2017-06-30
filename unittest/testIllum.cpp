///////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013 Academy of Motion Picture Arts and Sciences
// ("A.M.P.A.S."). Portions contributed by others as indicated.
// All rights reserved.
//
// A worldwide, royalty-free, non-exclusive right to copy, modify, create
// derivatives, and use, in source and binary forms, is hereby granted,
// subject to acceptance of this license. Performance of any of the
// aforementioned acts indicates acceptance to be bound by the following
// terms and conditions:
//
//  * Copies of source code, in whole or in part, must retain the
//    above copyright notice, this list of conditions and the
//    Disclaimer of Warranty.
//
//  * Use in binary form must retain the above copyright notice,
//    this list of conditions and the Disclaimer of Warranty in the
//    documentation and/or other materials provided with the distribution.
//
//  * Nothing in this license shall be deemed to grant any rights to
//    trademarks, copyrights, patents, trade secrets or any other
//    intellectual property of A.M.P.A.S. or any contributors, except
//    as expressly stated herein.
//
//  * Neither the name "A.M.P.A.S." nor the name of any other
//    contributors to this software may be used to endorse or promote
//    products derivative of or based on this software without express
//    prior written permission of A.M.P.A.S. or the contributors, as
//    appropriate.
//
// This license shall be construed pursuant to the laws of the State of
// California, and any disputes related thereto shall be subject to the
// jurisdiction of the courts therein.
//
// Disclaimer of Warranty: THIS SOFTWARE IS PROVIDED BY A.M.P.A.S. AND
// CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
// BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT ARE DISCLAIMED. IN NO
// EVENT SHALL A.M.P.A.S., OR ANY CONTRIBUTORS OR DISTRIBUTORS, BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, RESITUTIONARY,
// OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
// WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE ACADEMY
// SPECIFICALLY DISCLAIMS ANY REPRESENTATIONS OR WARRANTIES WHATSOEVER
// RELATED TO PATENT OR OTHER INTELLECTUAL PROPERTY RIGHTS IN THE ACADEMY
// COLOR ENCODING SYSTEM, OR APPLICATIONS THEREOF, HELD BY PARTIES OTHER
// THAN A.M.P.A.S., WHETHER DISCLOSED OR UNDISCLOSED.
///////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "../lib/mathOps.h"
#include "../lib/rta.h"

using namespace std;
using namespace rta;

BOOST_AUTO_TEST_CASE ( TestIllum_cctToxy ) {
    Illum illumObject;
    
    illumObject._type = "d50";
    illumObject._inc = 5;
    
    vector <double> xy = illumObject.cctToxy(5000);
    
    BOOST_CHECK_CLOSE ( xy[0], 0.3456619734948, 1e-9 );
    BOOST_CHECK_CLOSE ( xy[1], 0.3586032641691, 1e-9 );
};


BOOST_AUTO_TEST_CASE ( TestIllum_calSPD ) {
    Illum illumObject;
    
    illumObject._type = "d50";
    illumObject._inc = 5;
    
    illumObject.calDayLightSPD(5000);
    
    const double spd[107] = {   24.4978949755877,
                                27.1891380970612,
                                29.8803812185346,
                                39.6005856124086,
                                49.3207900062826,
                                52.9234909452740,
                                56.5261918842655,
                                58.2863692933629,
                                60.0465467024602,
                                58.9374754654423,
                                57.8284042284244,
                                66.3321986672105,
                                74.8359931059968,
                                81.0470608788071,
                                87.2581286516173,
                                88.9401444234118,
                                90.6221601952063,
                                90.9994142932283,
                                91.3766683912501,
                                93.2463519723246,
                                95.1160355533991,
                                93.5424463111289,
                                91.9688570688586,
                                93.8487650824512,
                                95.7286730960438,
                                96.1730210585583,
                                96.6173690210728,
                                96.8745483082553,
                                97.1317275954378,
                                99.6163972828030,
                                102.1010669701683,
                                101.4285401947830,
                                100.7560134193976,
                                101.5368117967032,
                                102.3176101740087,
                                101.1588050870044,
                                100.0000000000000,
                                98.8672487920966,
                                97.7344975841932,
                                98.3256924971888,
                                98.9168874101845,
                                96.2071139031367,
                                93.4973403960889,
                                95.5913911756801,
                                97.6854419552712,
                                98.4757935279747,
                                99.2661451006782,
                                99.1520792059532,
                                99.0380133112281,
                                97.3779908297348,
                                95.7179683482415,
                                97.2852940116115,
                                98.8526196749816,
                                97.2575832997790,
                                95.6625469245764,
                                96.9235194654881,
                                98.1844920063998,
                                100.5908749767109,
                                102.9972579470220,
                                101.0620719501407,
                                99.1268859532593,
                                93.2512715124010,
                                87.3756570715427,
                                89.4866296124544,
                                91.5976021533661,
                                92.2403288193421,
                                92.8830554853180,
                                84.8664480824888,
                                76.8498406796596,
                                81.6780321648151,
                                86.5062236499707,
                                89.5403942033879,
                                92.5745647568050,
                                85.4000426306844,
                                78.2255205045638,
                                67.9569774467047,
                                57.6884343888457,
                                70.3033080876698,
                                82.9181817864939,
                                80.5938616113981,
                                78.2695414363022
    };
    
    FORI(illumObject._data.size())
        BOOST_CHECK_CLOSE ( illumObject._data[i], spd[i], 1e-5 );
    
};
