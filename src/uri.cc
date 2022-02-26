
#line 1 "uri.rl"
#include "uri.h"
#include <sstream>

namespace miruy {

#line 9 "uri.cc"
static const int uri_parser_start = 453;
static const int uri_parser_first_final = 453;
static const int uri_parser_error = 0;

static const int uri_parser_en_main = 453;


#line 120 "uri.rl"


Uri::ptr Uri::Create(const std::string& uristr) {
    Uri::ptr uri(new Uri);
    int cs = 0;
    const char* mark = 0;
    
#line 25 "uri.cc"
	{
	cs = uri_parser_start;
	}

#line 127 "uri.rl"
    const char *p = uristr.data();
    const char *pe = p + uristr.size();
    const char* eof = pe;
    
#line 35 "uri.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 453:
	switch( (*p) ) {
		case 2: goto tr457;
		case 33: goto tr458;
		case 35: goto tr459;
		case 37: goto tr460;
		case 47: goto tr461;
		case 48: goto tr462;
		case 49: goto tr463;
		case 50: goto tr464;
		case 58: goto tr466;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr467;
		case 64: goto tr468;
		case 91: goto tr470;
		case 95: goto tr458;
		case 126: goto tr458;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto tr465;
		} else
			goto tr458;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 92 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr469;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto tr469;
		} else
			goto st0;
	} else
		goto tr458;
	goto st454;
tr546:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st454;
tr550:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st454;
tr554:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 113 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto st455;
		case 37: goto st3;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto st457;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 91 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 94 ) {
		if ( 123 <= (*p) && (*p) <= 125 )
			goto st0;
	} else
		goto st0;
	goto st454;
st0:
cs = 0;
	goto _out;
tr459:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr478:
#line 16 "uri.rl"
	{ mark = p; }
#line 94 "uri.rl"
	{
        uri->setQuery(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr480:
#line 94 "uri.rl"
	{
        uri->setQuery(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr482:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr545:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st455;
tr486:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr489:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr549:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st455;
tr493:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st455;
tr535:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st455;
tr553:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st455;
tr558:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st455;
tr564:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st455;
tr578:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 300 "uri.cc"
	switch( (*p) ) {
		case 37: goto tr475;
		case 60: goto st0;
		case 62: goto st0;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 34 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 35 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto st0;
	goto tr474;
tr474:
#line 16 "uri.rl"
	{ mark = p; }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 328 "uri.cc"
	switch( (*p) ) {
		case 37: goto st1;
		case 60: goto st0;
		case 62: goto st0;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 34 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 35 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto st0;
	goto st456;
tr475:
#line 16 "uri.rl"
	{ mark = p; }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 356 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st2;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st2;
	} else
		goto st2;
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st456;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st456;
	} else
		goto st456;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st4;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st4;
	} else
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st454;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st454;
	} else
		goto st454;
	goto st0;
tr467:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st457;
tr485:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st457;
tr548:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st457;
tr488:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st457;
tr492:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st457;
tr552:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st457;
tr496:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st457;
tr542:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st457;
tr556:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st457;
tr562:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st457;
tr567:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st457;
tr581:
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 553 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr478;
		case 37: goto tr479;
		case 60: goto st0;
		case 62: goto st0;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 91 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 94 ) {
		if ( 123 <= (*p) && (*p) <= 125 )
			goto st0;
	} else
		goto st0;
	goto tr477;
tr477:
#line 16 "uri.rl"
	{ mark = p; }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 580 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr480;
		case 37: goto st5;
		case 60: goto st0;
		case 62: goto st0;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 91 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 94 ) {
		if ( 123 <= (*p) && (*p) <= 125 )
			goto st0;
	} else
		goto st0;
	goto st458;
tr479:
#line 16 "uri.rl"
	{ mark = p; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 607 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st6;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st6;
	} else
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st458;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st458;
	} else
		goto st458;
	goto st0;
tr457:
#line 17 "uri.rl"
	{ mark = p; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 638 "uri.cc"
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st9;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 46 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 2: goto st11;
		case 48: goto st13;
		case 49: goto st27;
		case 50: goto st29;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st28;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 46 )
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 2: goto st15;
		case 48: goto st17;
		case 49: goto st23;
		case 50: goto st25;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st24;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st17;
	goto st0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 46 )
		goto st18;
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 2: goto st19;
		case 48: goto st459;
		case 49: goto st463;
		case 50: goto st465;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st464;
	goto st0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st20;
	goto st0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st459;
	goto st0;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	switch( (*p) ) {
		case 35: goto tr482;
		case 47: goto tr483;
		case 58: goto tr484;
		case 63: goto tr485;
	}
	goto st0;
tr505:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st460;
tr483:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 17 "uri.rl"
	{ mark = p; }
	goto st460;
tr560:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st460;
tr490:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st460;
tr494:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
	goto st460;
tr579:
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 819 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr486;
		case 37: goto st21;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr488;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 91 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 94 ) {
		if ( 123 <= (*p) && (*p) <= 125 )
			goto st0;
	} else
		goto st0;
	goto st460;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st22;
	} else
		goto st22;
	goto st0;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st460;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st460;
	} else
		goto st460;
	goto st0;
tr484:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 876 "uri.cc"
	switch( (*p) ) {
		case 35: goto tr489;
		case 47: goto tr490;
		case 63: goto tr492;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr491;
	goto st0;
tr491:
#line 17 "uri.rl"
	{ mark = p; }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 893 "uri.cc"
	switch( (*p) ) {
		case 35: goto tr493;
		case 47: goto tr494;
		case 63: goto tr496;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st462;
	goto st0;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
	switch( (*p) ) {
		case 35: goto tr482;
		case 47: goto tr483;
		case 58: goto tr484;
		case 63: goto tr485;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st464;
	goto st0;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
	switch( (*p) ) {
		case 35: goto tr482;
		case 47: goto tr483;
		case 58: goto tr484;
		case 63: goto tr485;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st459;
	goto st0;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	switch( (*p) ) {
		case 35: goto tr482;
		case 47: goto tr483;
		case 53: goto st466;
		case 58: goto tr484;
		case 63: goto tr485;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st459;
	goto st0;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	switch( (*p) ) {
		case 35: goto tr482;
		case 47: goto tr483;
		case 58: goto tr484;
		case 63: goto tr485;
	}
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st459;
	goto st0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 46 )
		goto st18;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st24;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 46 )
		goto st18;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st17;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 46: goto st18;
		case 53: goto st26;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st17;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 46 )
		goto st18;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st17;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 46 )
		goto st14;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 46 )
		goto st14;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 46: goto st14;
		case 53: goto st30;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 46 )
		goto st14;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st13;
	goto st0;
tr458:
#line 17 "uri.rl"
	{ mark = p; }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 1039 "uri.cc"
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st467;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st467;
	} else
		goto st0;
	goto st454;
tr460:
#line 17 "uri.rl"
	{ mark = p; }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1076 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st32;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st32;
	} else
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st467;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st467;
	} else
		goto st467;
	goto st0;
tr466:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st468;
tr499:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 1119 "uri.cc"
	switch( (*p) ) {
		case 33: goto st469;
		case 35: goto tr489;
		case 37: goto st33;
		case 47: goto tr490;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr492;
		case 64: goto tr500;
		case 95: goto st469;
		case 126: goto st469;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr502;
		} else
			goto st469;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st469;
	} else
		goto st469;
	goto st454;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	switch( (*p) ) {
		case 33: goto st469;
		case 35: goto st455;
		case 37: goto st33;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto st457;
		case 64: goto tr500;
		case 95: goto st469;
		case 126: goto st469;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 46 )
				goto st469;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st469;
	} else
		goto st469;
	goto st454;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st34;
	} else
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st469;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st469;
	} else
		goto st469;
	goto st0;
tr468:
#line 17 "uri.rl"
	{ mark = p; }
#line 35 "uri.rl"
	{
        if(mark)
            uri->setUser(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st470;
tr500:
#line 35 "uri.rl"
	{
        if(mark)
            uri->setUser(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 1234 "uri.cc"
	switch( (*p) ) {
		case 2: goto tr457;
		case 33: goto tr503;
		case 35: goto tr459;
		case 37: goto tr504;
		case 47: goto tr505;
		case 48: goto tr506;
		case 49: goto tr507;
		case 50: goto tr508;
		case 58: goto tr510;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr467;
		case 91: goto tr470;
		case 95: goto tr503;
		case 126: goto tr503;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto tr509;
		} else
			goto tr503;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 92 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr503;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto tr503;
		} else
			goto st0;
	} else
		goto tr503;
	goto st454;
tr503:
#line 17 "uri.rl"
	{ mark = p; }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 1284 "uri.cc"
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st471;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st471;
	} else
		goto st471;
	goto st454;
tr504:
#line 17 "uri.rl"
	{ mark = p; }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1323 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st36;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st36;
	} else
		goto st36;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st471;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st471;
	} else
		goto st471;
	goto st0;
tr510:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st472;
tr512:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 1366 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr489;
		case 37: goto st3;
		case 47: goto tr490;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr492;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 48 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto tr513;
	goto st454;
tr513:
#line 17 "uri.rl"
	{ mark = p; }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 1398 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr493;
		case 37: goto st3;
		case 47: goto tr494;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr496;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 48 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto st473;
	goto st454;
tr506:
#line 17 "uri.rl"
	{ mark = p; }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 1430 "uri.cc"
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st475;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st471;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st471;
	} else
		goto st471;
	goto st454;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
	switch( (*p) ) {
		case 2: goto st11;
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 47: goto tr483;
		case 48: goto st476;
		case 49: goto st484;
		case 50: goto st486;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st485;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st477;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st471;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st471;
	} else
		goto st471;
	goto st454;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	switch( (*p) ) {
		case 2: goto st15;
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 47: goto tr483;
		case 48: goto st478;
		case 49: goto st480;
		case 50: goto st482;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st481;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st479;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st471;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st471;
	} else
		goto st471;
	goto st454;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	switch( (*p) ) {
		case 2: goto st19;
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st471;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st471;
	} else
		goto st471;
	goto st454;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st479;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st481;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st479;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st478;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st479;
		case 47: goto tr483;
		case 53: goto st483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st478;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st479;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st478;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st477;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st485;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st477;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st476;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st477;
		case 47: goto tr483;
		case 53: goto st487;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st476;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st477;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st476;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
tr507:
#line 17 "uri.rl"
	{ mark = p; }
	goto st488;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
#line 1993 "uri.cc"
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st475;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st489;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
tr509:
#line 17 "uri.rl"
	{ mark = p; }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 2039 "uri.cc"
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st475;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st474;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
tr508:
#line 17 "uri.rl"
	{ mark = p; }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 2085 "uri.cc"
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st475;
		case 47: goto tr483;
		case 53: goto st491;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st474;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
	switch( (*p) ) {
		case 33: goto st471;
		case 35: goto tr482;
		case 37: goto st35;
		case 46: goto st475;
		case 47: goto tr483;
		case 58: goto tr512;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st471;
		case 126: goto st471;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st474;
		} else
			goto st471;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st471;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st471;
		} else
			goto st0;
	} else
		goto st471;
	goto st454;
tr470:
#line 17 "uri.rl"
	{ mark = p; }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 2173 "uri.cc"
	switch( (*p) ) {
		case 58: goto st145;
		case 118: goto st224;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st38;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st38;
	} else
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	if ( (*p) == 58 )
		goto st42;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st39;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st39;
	} else
		goto st39;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 58 )
		goto st42;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st40;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st40;
	} else
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 58 )
		goto st42;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st41;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st41;
	} else
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	if ( (*p) == 58 )
		goto st42;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	if ( (*p) == 58 )
		goto st140;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st43;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st43;
	} else
		goto st43;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 58 )
		goto st47;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st44;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st44;
	} else
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 58 )
		goto st47;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st45;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st45;
	} else
		goto st45;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	if ( (*p) == 58 )
		goto st47;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st46;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st46;
	} else
		goto st46;
	goto st0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 58 )
		goto st47;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 58 )
		goto st135;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st48;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st48;
	} else
		goto st48;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 58 )
		goto st52;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st49;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st49;
	} else
		goto st49;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 58 )
		goto st52;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st50;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st50;
	} else
		goto st50;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 58 )
		goto st52;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st51;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st51;
	} else
		goto st51;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 58 )
		goto st52;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 58 )
		goto st130;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st53;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st53;
	} else
		goto st53;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 58 )
		goto st57;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st54;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st54;
	} else
		goto st54;
	goto st0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 58 )
		goto st57;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st55;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st55;
	} else
		goto st55;
	goto st0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 58 )
		goto st57;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st56;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st56;
	} else
		goto st56;
	goto st0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 58 )
		goto st57;
	goto st0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 58 )
		goto st125;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st58;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st58;
	} else
		goto st58;
	goto st0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 58 )
		goto st62;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st59;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st59;
	} else
		goto st59;
	goto st0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 58 )
		goto st62;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st60;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st60;
	} else
		goto st60;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 58 )
		goto st62;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st61;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st61;
	} else
		goto st61;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 58 )
		goto st62;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 58 )
		goto st112;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st63;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st63;
	} else
		goto st63;
	goto st0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	if ( (*p) == 58 )
		goto st67;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st64;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st64;
	} else
		goto st64;
	goto st0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 58 )
		goto st67;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st65;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st65;
	} else
		goto st65;
	goto st0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	if ( (*p) == 58 )
		goto st67;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st66;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st66;
	} else
		goto st66;
	goto st0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 58 )
		goto st67;
	goto st0;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st95;
		case 49: goto st103;
		case 50: goto st106;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st109;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st111;
	} else
		goto st111;
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st69;
	goto st0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st70;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 46 )
		goto st71;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 2: goto st72;
		case 48: goto st74;
		case 49: goto st91;
		case 50: goto st93;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st92;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st73;
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st74;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 46 )
		goto st75;
	goto st0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 2: goto st76;
		case 48: goto st78;
		case 49: goto st87;
		case 50: goto st89;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st88;
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st77;
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st78;
	goto st0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 46 )
		goto st79;
	goto st0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 2: goto st80;
		case 48: goto st82;
		case 49: goto st83;
		case 50: goto st85;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st84;
	goto st0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st81;
	goto st0;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st82;
	goto st0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 93 )
		goto st459;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 93 )
		goto st459;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st84;
	goto st0;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 93 )
		goto st459;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st82;
	goto st0;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 53: goto st86;
		case 93: goto st459;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st82;
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 93 )
		goto st459;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st82;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) == 46 )
		goto st79;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st88;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 46 )
		goto st79;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st78;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 46: goto st79;
		case 53: goto st90;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st78;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 46 )
		goto st79;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st78;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 46 )
		goto st75;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st92;
	goto st0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 46 )
		goto st75;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st74;
	goto st0;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 46: goto st75;
		case 53: goto st94;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st74;
	goto st0;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 46 )
		goto st75;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st74;
	goto st0;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st96;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st96;
	} else
		goto st96;
	goto st0;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( (*p) == 58 )
		goto st99;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st97;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st97;
	} else
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 58 )
		goto st99;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st98;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st98;
	} else
		goto st98;
	goto st0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 58 )
		goto st99;
	goto st0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 58 )
		goto st82;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st100;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st100;
	} else
		goto st100;
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 93 )
		goto st459;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st101;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st101;
	} else
		goto st101;
	goto st0;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 93 )
		goto st459;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st102;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st102;
	} else
		goto st102;
	goto st0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 93 )
		goto st459;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st82;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st82;
	} else
		goto st82;
	goto st0;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st104;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st96;
	} else
		goto st96;
	goto st0;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st105;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st97;
	} else
		goto st97;
	goto st0;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st98;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st98;
	} else
		goto st98;
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st108;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st107;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st96;
	} else
		goto st96;
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st97;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st97;
	} else
		goto st97;
	goto st0;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st105;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st97;
		} else if ( (*p) >= 65 )
			goto st97;
	} else
		goto st97;
	goto st0;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st107;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st96;
	} else
		goto st96;
	goto st0;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st100;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st100;
	} else
		goto st100;
	goto st0;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 58 )
		goto st99;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st96;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st96;
	} else
		goto st96;
	goto st0;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st113;
		case 49: goto st117;
		case 50: goto st120;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st123;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st124;
	} else
		goto st124;
	goto st0;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st114;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto st0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 58 )
		goto st110;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st115;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st115;
	} else
		goto st115;
	goto st0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 58 )
		goto st110;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st116;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st116;
	} else
		goto st116;
	goto st0;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 58 )
		goto st110;
	goto st0;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st118;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto st0;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st119;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st115;
	} else
		goto st115;
	goto st0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st116;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st116;
	} else
		goto st116;
	goto st0;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st122;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto st0;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st115;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st115;
	} else
		goto st115;
	goto st0;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st119;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st115;
		} else if ( (*p) >= 65 )
			goto st115;
	} else
		goto st115;
	goto st0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto st0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 58 )
		goto st110;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st114;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto st0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st126;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st126;
	} else
		goto st126;
	goto st0;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 58 )
		goto st112;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st127;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st127;
	} else
		goto st127;
	goto st0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 58 )
		goto st112;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st128;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st128;
	} else
		goto st128;
	goto st0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 58 )
		goto st112;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st129;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st129;
	} else
		goto st129;
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 58 )
		goto st112;
	goto st0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st131;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st131;
	} else
		goto st131;
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 58 )
		goto st125;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st132;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st132;
	} else
		goto st132;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 58 )
		goto st125;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st133;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st133;
	} else
		goto st133;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 58 )
		goto st125;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st134;
	} else
		goto st134;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) == 58 )
		goto st125;
	goto st0;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st136;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st136;
	} else
		goto st136;
	goto st0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 58 )
		goto st130;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st137;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st137;
	} else
		goto st137;
	goto st0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	if ( (*p) == 58 )
		goto st130;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st138;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st138;
	} else
		goto st138;
	goto st0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 58 )
		goto st130;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st139;
	} else
		goto st139;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 58 )
		goto st130;
	goto st0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st141;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st141;
	} else
		goto st141;
	goto st0;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 58 )
		goto st135;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st142;
	} else
		goto st142;
	goto st0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 58 )
		goto st135;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st143;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st143;
	} else
		goto st143;
	goto st0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 58 )
		goto st135;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st144;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st144;
	} else
		goto st144;
	goto st0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 58 )
		goto st135;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 58 )
		goto st146;
	goto st0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st147;
		case 49: goto st216;
		case 50: goto st219;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st222;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st223;
	} else
		goto st223;
	goto st0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st148;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st148;
	} else
		goto st148;
	goto st0;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st149;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st149;
	} else
		goto st149;
	goto st0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st150;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st150;
	} else
		goto st150;
	goto st0;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 58: goto st151;
		case 93: goto st459;
	}
	goto st0;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st152;
		case 49: goto st208;
		case 50: goto st211;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st214;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st215;
	} else
		goto st215;
	goto st0;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st153;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto st0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st154;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st154;
	} else
		goto st154;
	goto st0;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st155;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st155;
	} else
		goto st155;
	goto st0;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 58: goto st156;
		case 93: goto st459;
	}
	goto st0;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st157;
		case 49: goto st200;
		case 50: goto st203;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st206;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st207;
	} else
		goto st207;
	goto st0;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st158;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto st0;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st159;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st159;
	} else
		goto st159;
	goto st0;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st160;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st160;
	} else
		goto st160;
	goto st0;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 58: goto st161;
		case 93: goto st459;
	}
	goto st0;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st162;
		case 49: goto st192;
		case 50: goto st195;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st198;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st199;
	} else
		goto st199;
	goto st0;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st163;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto st0;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st164;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st164;
	} else
		goto st164;
	goto st0;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st165;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st165;
	} else
		goto st165;
	goto st0;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 58: goto st166;
		case 93: goto st459;
	}
	goto st0;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st167;
		case 49: goto st184;
		case 50: goto st187;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st190;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st191;
	} else
		goto st191;
	goto st0;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st168;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st168;
	} else
		goto st168;
	goto st0;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st169;
	} else
		goto st169;
	goto st0;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st170;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st170;
	} else
		goto st170;
	goto st0;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 58: goto st171;
		case 93: goto st459;
	}
	goto st0;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 2: goto st68;
		case 48: goto st172;
		case 49: goto st176;
		case 50: goto st179;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st182;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st183;
	} else
		goto st183;
	goto st0;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st173;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto st0;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st174;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st174;
	} else
		goto st174;
	goto st0;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st175;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st175;
	} else
		goto st175;
	goto st0;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 58: goto st110;
		case 93: goto st459;
	}
	goto st0;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st177;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto st0;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st174;
	} else
		goto st174;
	goto st0;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st175;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st175;
	} else
		goto st175;
	goto st0;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st181;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st180;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto st0;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st174;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st174;
	} else
		goto st174;
	goto st0;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st178;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st174;
		} else if ( (*p) >= 65 )
			goto st174;
	} else
		goto st174;
	goto st0;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st180;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto st0;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 58: goto st110;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st173;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto st0;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st185;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st168;
	} else
		goto st168;
	goto st0;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st186;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st169;
	} else
		goto st169;
	goto st0;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st170;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st170;
	} else
		goto st170;
	goto st0;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st189;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st188;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st168;
	} else
		goto st168;
	goto st0;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st169;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st169;
	} else
		goto st169;
	goto st0;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st186;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st169;
		} else if ( (*p) >= 65 )
			goto st169;
	} else
		goto st169;
	goto st0;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st188;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st168;
	} else
		goto st168;
	goto st0;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 58: goto st171;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st168;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st168;
	} else
		goto st168;
	goto st0;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st193;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto st0;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st194;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st164;
	} else
		goto st164;
	goto st0;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st165;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st165;
	} else
		goto st165;
	goto st0;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st197;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st196;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto st0;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st164;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st164;
	} else
		goto st164;
	goto st0;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st194;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st164;
		} else if ( (*p) >= 65 )
			goto st164;
	} else
		goto st164;
	goto st0;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st196;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto st0;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 58: goto st166;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st163;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto st0;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st201;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto st0;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st202;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st159;
	} else
		goto st159;
	goto st0;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st160;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st160;
	} else
		goto st160;
	goto st0;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st205;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st204;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto st0;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st159;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st159;
	} else
		goto st159;
	goto st0;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st202;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st159;
		} else if ( (*p) >= 65 )
			goto st159;
	} else
		goto st159;
	goto st0;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st204;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto st0;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 58: goto st161;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st158;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto st0;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st209;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto st0;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st210;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st154;
	} else
		goto st154;
	goto st0;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st155;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st155;
	} else
		goto st155;
	goto st0;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st213;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st212;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto st0;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st154;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st154;
	} else
		goto st154;
	goto st0;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st210;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st154;
		} else if ( (*p) >= 65 )
			goto st154;
	} else
		goto st154;
	goto st0;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st212;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto st0;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 58: goto st156;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st153;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto st0;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st217;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st148;
	} else
		goto st148;
	goto st0;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st218;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st149;
	} else
		goto st149;
	goto st0;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st150;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st150;
	} else
		goto st150;
	goto st0;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	switch( (*p) ) {
		case 46: goto st71;
		case 53: goto st221;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st220;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st148;
	} else
		goto st148;
	goto st0;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st149;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st149;
	} else
		goto st149;
	goto st0;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st218;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st149;
		} else if ( (*p) >= 65 )
			goto st149;
	} else
		goto st149;
	goto st0;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 46: goto st71;
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st220;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st148;
	} else
		goto st148;
	goto st0;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 58: goto st151;
		case 93: goto st459;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st148;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st148;
	} else
		goto st148;
	goto st0;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st225;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st225;
	} else
		goto st225;
	goto st0;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	if ( (*p) == 46 )
		goto st226;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st225;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st225;
	} else
		goto st225;
	goto st0;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	switch( (*p) ) {
		case 33: goto st227;
		case 36: goto st227;
		case 61: goto st227;
		case 95: goto st227;
		case 126: goto st227;
	}
	if ( (*p) < 48 ) {
		if ( 38 <= (*p) && (*p) <= 46 )
			goto st227;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st227;
		} else if ( (*p) >= 65 )
			goto st227;
	} else
		goto st227;
	goto st0;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	switch( (*p) ) {
		case 33: goto st227;
		case 36: goto st227;
		case 61: goto st227;
		case 93: goto st459;
		case 95: goto st227;
		case 126: goto st227;
	}
	if ( (*p) < 48 ) {
		if ( 38 <= (*p) && (*p) <= 46 )
			goto st227;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st227;
		} else if ( (*p) >= 65 )
			goto st227;
	} else
		goto st227;
	goto st0;
tr502:
#line 17 "uri.rl"
	{ mark = p; }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 5020 "uri.cc"
	switch( (*p) ) {
		case 33: goto st469;
		case 35: goto tr493;
		case 37: goto st33;
		case 47: goto tr494;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr496;
		case 64: goto tr500;
		case 95: goto st469;
		case 126: goto st469;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st492;
		} else
			goto st469;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st469;
	} else
		goto st469;
	goto st454;
tr461:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st493;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
#line 5067 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr486;
		case 37: goto st21;
		case 47: goto st494;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr488;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 91 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 94 ) {
		if ( 123 <= (*p) && (*p) <= 125 )
			goto st0;
	} else
		goto st0;
	goto st460;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
	switch( (*p) ) {
		case 2: goto tr533;
		case 33: goto tr534;
		case 35: goto tr535;
		case 37: goto tr536;
		case 47: goto tr505;
		case 48: goto tr537;
		case 49: goto tr538;
		case 50: goto tr539;
		case 58: goto tr541;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr542;
		case 64: goto tr543;
		case 91: goto tr544;
		case 95: goto tr534;
		case 126: goto tr534;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto tr540;
		} else
			goto tr534;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 92 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto tr534;
	} else
		goto tr534;
	goto st460;
tr533:
#line 17 "uri.rl"
	{ mark = p; }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 5139 "uri.cc"
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st229;
	goto st0;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st230;
	goto st0;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) == 46 )
		goto st231;
	goto st0;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 2: goto st232;
		case 48: goto st234;
		case 49: goto st246;
		case 50: goto st248;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st247;
	goto st0;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st233;
	goto st0;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st234;
	goto st0;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) == 46 )
		goto st235;
	goto st0;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
	switch( (*p) ) {
		case 2: goto st236;
		case 48: goto st238;
		case 49: goto st242;
		case 50: goto st244;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st243;
	goto st0;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st237;
	goto st0;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st238;
	goto st0;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
	if ( (*p) == 46 )
		goto st239;
	goto st0;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	switch( (*p) ) {
		case 2: goto st240;
		case 48: goto st495;
		case 49: goto st498;
		case 50: goto st500;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st499;
	goto st0;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st241;
	goto st0;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st495;
	goto st0;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
	switch( (*p) ) {
		case 35: goto tr545;
		case 47: goto tr546;
		case 58: goto tr547;
		case 63: goto tr548;
	}
	goto st0;
tr547:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 5274 "uri.cc"
	switch( (*p) ) {
		case 35: goto tr549;
		case 47: goto tr550;
		case 63: goto tr552;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr551;
	goto st0;
tr551:
#line 17 "uri.rl"
	{ mark = p; }
	goto st497;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
#line 5291 "uri.cc"
	switch( (*p) ) {
		case 35: goto tr553;
		case 47: goto tr554;
		case 63: goto tr556;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st497;
	goto st0;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
	switch( (*p) ) {
		case 35: goto tr545;
		case 47: goto tr546;
		case 58: goto tr547;
		case 63: goto tr548;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st499;
	goto st0;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
	switch( (*p) ) {
		case 35: goto tr545;
		case 47: goto tr546;
		case 58: goto tr547;
		case 63: goto tr548;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st495;
	goto st0;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
	switch( (*p) ) {
		case 35: goto tr545;
		case 47: goto tr546;
		case 53: goto st501;
		case 58: goto tr547;
		case 63: goto tr548;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st495;
	goto st0;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
	switch( (*p) ) {
		case 35: goto tr545;
		case 47: goto tr546;
		case 58: goto tr547;
		case 63: goto tr548;
	}
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st495;
	goto st0;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
	if ( (*p) == 46 )
		goto st239;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st243;
	goto st0;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
	if ( (*p) == 46 )
		goto st239;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st238;
	goto st0;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	switch( (*p) ) {
		case 46: goto st239;
		case 53: goto st245;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st238;
	goto st0;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	if ( (*p) == 46 )
		goto st239;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st238;
	goto st0;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
	if ( (*p) == 46 )
		goto st235;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st247;
	goto st0;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) == 46 )
		goto st235;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st234;
	goto st0;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
	switch( (*p) ) {
		case 46: goto st235;
		case 53: goto st249;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st234;
	goto st0;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	if ( (*p) == 46 )
		goto st235;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st234;
	goto st0;
tr534:
#line 17 "uri.rl"
	{ mark = p; }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 5437 "uri.cc"
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st502;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st502;
	} else
		goto st0;
	goto st460;
tr536:
#line 17 "uri.rl"
	{ mark = p; }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 5474 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st251;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st251;
	} else
		goto st251;
	goto st0;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st502;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st502;
	} else
		goto st502;
	goto st0;
tr541:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st503;
tr561:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 5517 "uri.cc"
	switch( (*p) ) {
		case 33: goto st504;
		case 35: goto tr564;
		case 37: goto st252;
		case 47: goto tr490;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr567;
		case 64: goto tr563;
		case 95: goto st504;
		case 126: goto st504;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr566;
		} else
			goto st504;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st504;
	} else
		goto st504;
	goto st460;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
	switch( (*p) ) {
		case 33: goto st504;
		case 35: goto tr486;
		case 37: goto st252;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr488;
		case 64: goto tr563;
		case 95: goto st504;
		case 126: goto st504;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 46 )
				goto st504;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st504;
	} else
		goto st504;
	goto st460;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st253;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st253;
	} else
		goto st253;
	goto st0;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st504;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st504;
	} else
		goto st504;
	goto st0;
tr543:
#line 17 "uri.rl"
	{ mark = p; }
#line 35 "uri.rl"
	{
        if(mark)
            uri->setUser(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st505;
tr563:
#line 35 "uri.rl"
	{
        if(mark)
            uri->setUser(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 5632 "uri.cc"
	switch( (*p) ) {
		case 2: goto tr533;
		case 33: goto tr568;
		case 35: goto tr535;
		case 37: goto tr569;
		case 47: goto tr505;
		case 48: goto tr570;
		case 49: goto tr571;
		case 50: goto tr572;
		case 58: goto tr574;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr542;
		case 91: goto tr544;
		case 95: goto tr568;
		case 126: goto tr568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto tr573;
		} else
			goto tr568;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 92 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr568;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto tr568;
		} else
			goto st0;
	} else
		goto tr568;
	goto st460;
tr568:
#line 17 "uri.rl"
	{ mark = p; }
	goto st506;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
#line 5682 "uri.cc"
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st506;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st506;
	} else
		goto st506;
	goto st460;
tr569:
#line 17 "uri.rl"
	{ mark = p; }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 5721 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st255;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st255;
	} else
		goto st255;
	goto st0;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st506;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st506;
	} else
		goto st506;
	goto st0;
tr574:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st507;
tr576:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 5764 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr564;
		case 37: goto st21;
		case 47: goto tr490;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr567;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 48 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto tr577;
	goto st460;
tr577:
#line 17 "uri.rl"
	{ mark = p; }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 5796 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr578;
		case 37: goto st21;
		case 47: goto tr579;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr581;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 48 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto st508;
	goto st460;
tr570:
#line 17 "uri.rl"
	{ mark = p; }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 5828 "uri.cc"
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st510;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st506;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st506;
	} else
		goto st506;
	goto st460;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
	switch( (*p) ) {
		case 2: goto st232;
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 47: goto tr560;
		case 48: goto st511;
		case 49: goto st519;
		case 50: goto st521;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st520;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st512;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st506;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st506;
	} else
		goto st506;
	goto st460;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
	switch( (*p) ) {
		case 2: goto st236;
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 47: goto tr560;
		case 48: goto st513;
		case 49: goto st515;
		case 50: goto st517;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st516;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st514;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st506;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st506;
	} else
		goto st506;
	goto st460;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
	switch( (*p) ) {
		case 2: goto st240;
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st506;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st506;
	} else
		goto st506;
	goto st460;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st514;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st516;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st514;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st513;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st514;
		case 47: goto tr560;
		case 53: goto st518;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st513;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st514;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st513;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st512;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st520;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st512;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st511;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st512;
		case 47: goto tr560;
		case 53: goto st522;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st511;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st512;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st511;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
tr571:
#line 17 "uri.rl"
	{ mark = p; }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 6391 "uri.cc"
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st510;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st524;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
tr573:
#line 17 "uri.rl"
	{ mark = p; }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 6437 "uri.cc"
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st510;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st509;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
tr572:
#line 17 "uri.rl"
	{ mark = p; }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 6483 "uri.cc"
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st510;
		case 47: goto tr560;
		case 53: goto st526;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st509;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
	switch( (*p) ) {
		case 33: goto st506;
		case 35: goto tr558;
		case 37: goto st254;
		case 46: goto st510;
		case 47: goto tr560;
		case 58: goto tr576;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 95: goto st506;
		case 126: goto st506;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st509;
		} else
			goto st506;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st506;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st506;
		} else
			goto st0;
	} else
		goto st506;
	goto st460;
tr544:
#line 17 "uri.rl"
	{ mark = p; }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 6571 "uri.cc"
	switch( (*p) ) {
		case 58: goto st364;
		case 118: goto st443;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st257;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st257;
	} else
		goto st257;
	goto st0;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
	if ( (*p) == 58 )
		goto st261;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st258;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st258;
	} else
		goto st258;
	goto st0;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	if ( (*p) == 58 )
		goto st261;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st259;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st259;
	} else
		goto st259;
	goto st0;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	if ( (*p) == 58 )
		goto st261;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st260;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st260;
	} else
		goto st260;
	goto st0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	if ( (*p) == 58 )
		goto st261;
	goto st0;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	if ( (*p) == 58 )
		goto st359;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st262;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st262;
	} else
		goto st262;
	goto st0;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	if ( (*p) == 58 )
		goto st266;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st263;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st263;
	} else
		goto st263;
	goto st0;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	if ( (*p) == 58 )
		goto st266;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st264;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st264;
	} else
		goto st264;
	goto st0;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	if ( (*p) == 58 )
		goto st266;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st265;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st265;
	} else
		goto st265;
	goto st0;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	if ( (*p) == 58 )
		goto st266;
	goto st0;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	if ( (*p) == 58 )
		goto st354;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st267;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st267;
	} else
		goto st267;
	goto st0;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	if ( (*p) == 58 )
		goto st271;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st268;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st268;
	} else
		goto st268;
	goto st0;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	if ( (*p) == 58 )
		goto st271;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st269;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st269;
	} else
		goto st269;
	goto st0;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	if ( (*p) == 58 )
		goto st271;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st270;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st270;
	} else
		goto st270;
	goto st0;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	if ( (*p) == 58 )
		goto st271;
	goto st0;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	if ( (*p) == 58 )
		goto st349;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st272;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st272;
	} else
		goto st272;
	goto st0;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
	if ( (*p) == 58 )
		goto st276;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st273;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st273;
	} else
		goto st273;
	goto st0;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	if ( (*p) == 58 )
		goto st276;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st274;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st274;
	} else
		goto st274;
	goto st0;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	if ( (*p) == 58 )
		goto st276;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st275;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st275;
	} else
		goto st275;
	goto st0;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
	if ( (*p) == 58 )
		goto st276;
	goto st0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	if ( (*p) == 58 )
		goto st344;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st277;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st277;
	} else
		goto st277;
	goto st0;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
	if ( (*p) == 58 )
		goto st281;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st278;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st278;
	} else
		goto st278;
	goto st0;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	if ( (*p) == 58 )
		goto st281;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st279;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st279;
	} else
		goto st279;
	goto st0;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
	if ( (*p) == 58 )
		goto st281;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st280;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st280;
	} else
		goto st280;
	goto st0;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
	if ( (*p) == 58 )
		goto st281;
	goto st0;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
	if ( (*p) == 58 )
		goto st331;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st282;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st282;
	} else
		goto st282;
	goto st0;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	if ( (*p) == 58 )
		goto st286;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st283;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st283;
	} else
		goto st283;
	goto st0;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) == 58 )
		goto st286;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st284;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st284;
	} else
		goto st284;
	goto st0;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
	if ( (*p) == 58 )
		goto st286;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st285;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st285;
	} else
		goto st285;
	goto st0;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
	if ( (*p) == 58 )
		goto st286;
	goto st0;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st314;
		case 49: goto st322;
		case 50: goto st325;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st328;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st330;
	} else
		goto st330;
	goto st0;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st288;
	goto st0;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st289;
	goto st0;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
	if ( (*p) == 46 )
		goto st290;
	goto st0;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
	switch( (*p) ) {
		case 2: goto st291;
		case 48: goto st293;
		case 49: goto st310;
		case 50: goto st312;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st311;
	goto st0;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st292;
	goto st0;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st293;
	goto st0;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	if ( (*p) == 46 )
		goto st294;
	goto st0;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
	switch( (*p) ) {
		case 2: goto st295;
		case 48: goto st297;
		case 49: goto st306;
		case 50: goto st308;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st307;
	goto st0;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st296;
	goto st0;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st297;
	goto st0;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
	if ( (*p) == 46 )
		goto st298;
	goto st0;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
	switch( (*p) ) {
		case 2: goto st299;
		case 48: goto st301;
		case 49: goto st302;
		case 50: goto st304;
	}
	if ( 51 <= (*p) && (*p) <= 57 )
		goto st303;
	goto st0;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	if ( 48 <= (*p) && (*p) <= 52 )
		goto st300;
	goto st0;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st301;
	goto st0;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
	if ( (*p) == 93 )
		goto st495;
	goto st0;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	if ( (*p) == 93 )
		goto st495;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st303;
	goto st0;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) == 93 )
		goto st495;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st301;
	goto st0;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	switch( (*p) ) {
		case 53: goto st305;
		case 93: goto st495;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st301;
	goto st0;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) == 93 )
		goto st495;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st301;
	goto st0;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 46 )
		goto st298;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st307;
	goto st0;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	if ( (*p) == 46 )
		goto st298;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st297;
	goto st0;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	switch( (*p) ) {
		case 46: goto st298;
		case 53: goto st309;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st297;
	goto st0;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	if ( (*p) == 46 )
		goto st298;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st297;
	goto st0;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) == 46 )
		goto st294;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st311;
	goto st0;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	if ( (*p) == 46 )
		goto st294;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st293;
	goto st0;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	switch( (*p) ) {
		case 46: goto st294;
		case 53: goto st313;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st293;
	goto st0;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	if ( (*p) == 46 )
		goto st294;
	if ( 48 <= (*p) && (*p) <= 53 )
		goto st293;
	goto st0;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st315;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st315;
	} else
		goto st315;
	goto st0;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	if ( (*p) == 58 )
		goto st318;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st316;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st316;
	} else
		goto st316;
	goto st0;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	if ( (*p) == 58 )
		goto st318;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st317;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st317;
	} else
		goto st317;
	goto st0;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	if ( (*p) == 58 )
		goto st318;
	goto st0;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	if ( (*p) == 58 )
		goto st301;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st319;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st319;
	} else
		goto st319;
	goto st0;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	if ( (*p) == 93 )
		goto st495;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st320;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st320;
	} else
		goto st320;
	goto st0;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	if ( (*p) == 93 )
		goto st495;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st321;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st321;
	} else
		goto st321;
	goto st0;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	if ( (*p) == 93 )
		goto st495;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st301;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st301;
	} else
		goto st301;
	goto st0;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st323;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st315;
	} else
		goto st315;
	goto st0;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st324;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st316;
	} else
		goto st316;
	goto st0;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st317;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st317;
	} else
		goto st317;
	goto st0;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st327;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st326;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st315;
	} else
		goto st315;
	goto st0;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st316;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st316;
	} else
		goto st316;
	goto st0;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st324;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st316;
		} else if ( (*p) >= 65 )
			goto st316;
	} else
		goto st316;
	goto st0;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st326;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st315;
	} else
		goto st315;
	goto st0;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st319;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st319;
	} else
		goto st319;
	goto st0;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( (*p) == 58 )
		goto st318;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st315;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st315;
	} else
		goto st315;
	goto st0;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st332;
		case 49: goto st336;
		case 50: goto st339;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st342;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st343;
	} else
		goto st343;
	goto st0;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st333;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st333;
	} else
		goto st333;
	goto st0;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 58 )
		goto st329;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st334;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st334;
	} else
		goto st334;
	goto st0;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 58 )
		goto st329;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st335;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st335;
	} else
		goto st335;
	goto st0;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 58 )
		goto st329;
	goto st0;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st337;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st333;
	} else
		goto st333;
	goto st0;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st338;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st334;
	} else
		goto st334;
	goto st0;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st335;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st335;
	} else
		goto st335;
	goto st0;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st341;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st340;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st333;
	} else
		goto st333;
	goto st0;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st334;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st334;
	} else
		goto st334;
	goto st0;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st338;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st334;
		} else if ( (*p) >= 65 )
			goto st334;
	} else
		goto st334;
	goto st0;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st340;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st333;
	} else
		goto st333;
	goto st0;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	if ( (*p) == 58 )
		goto st329;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st333;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st333;
	} else
		goto st333;
	goto st0;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st345;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st345;
	} else
		goto st345;
	goto st0;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) == 58 )
		goto st331;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st346;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st346;
	} else
		goto st346;
	goto st0;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	if ( (*p) == 58 )
		goto st331;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st347;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st347;
	} else
		goto st347;
	goto st0;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	if ( (*p) == 58 )
		goto st331;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st348;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st348;
	} else
		goto st348;
	goto st0;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	if ( (*p) == 58 )
		goto st331;
	goto st0;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st350;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st350;
	} else
		goto st350;
	goto st0;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 58 )
		goto st344;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st351;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st351;
	} else
		goto st351;
	goto st0;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 58 )
		goto st344;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st352;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st352;
	} else
		goto st352;
	goto st0;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 58 )
		goto st344;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st353;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st353;
	} else
		goto st353;
	goto st0;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 58 )
		goto st344;
	goto st0;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st355;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st355;
	} else
		goto st355;
	goto st0;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 58 )
		goto st349;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st356;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st356;
	} else
		goto st356;
	goto st0;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	if ( (*p) == 58 )
		goto st349;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st357;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st357;
	} else
		goto st357;
	goto st0;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	if ( (*p) == 58 )
		goto st349;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st358;
	} else
		goto st358;
	goto st0;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	if ( (*p) == 58 )
		goto st349;
	goto st0;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st360;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st360;
	} else
		goto st360;
	goto st0;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) == 58 )
		goto st354;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st361;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st361;
	} else
		goto st361;
	goto st0;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
	if ( (*p) == 58 )
		goto st354;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st362;
	} else
		goto st362;
	goto st0;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
	if ( (*p) == 58 )
		goto st354;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st363;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st363;
	} else
		goto st363;
	goto st0;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	if ( (*p) == 58 )
		goto st354;
	goto st0;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) == 58 )
		goto st365;
	goto st0;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st366;
		case 49: goto st435;
		case 50: goto st438;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st441;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st442;
	} else
		goto st442;
	goto st0;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st367;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st367;
	} else
		goto st367;
	goto st0;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	switch( (*p) ) {
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st368;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st368;
	} else
		goto st368;
	goto st0;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	switch( (*p) ) {
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st369;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st369;
	} else
		goto st369;
	goto st0;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	switch( (*p) ) {
		case 58: goto st370;
		case 93: goto st495;
	}
	goto st0;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st371;
		case 49: goto st427;
		case 50: goto st430;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st433;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st434;
	} else
		goto st434;
	goto st0;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st372;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st372;
	} else
		goto st372;
	goto st0;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
	switch( (*p) ) {
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st373;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st373;
	} else
		goto st373;
	goto st0;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	switch( (*p) ) {
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st374;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st374;
	} else
		goto st374;
	goto st0;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	switch( (*p) ) {
		case 58: goto st375;
		case 93: goto st495;
	}
	goto st0;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st376;
		case 49: goto st419;
		case 50: goto st422;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st425;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st426;
	} else
		goto st426;
	goto st0;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st377;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st377;
	} else
		goto st377;
	goto st0;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	switch( (*p) ) {
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st378;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st378;
	} else
		goto st378;
	goto st0;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	switch( (*p) ) {
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st379;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st379;
	} else
		goto st379;
	goto st0;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	switch( (*p) ) {
		case 58: goto st380;
		case 93: goto st495;
	}
	goto st0;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st381;
		case 49: goto st411;
		case 50: goto st414;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st417;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st418;
	} else
		goto st418;
	goto st0;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st382;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st382;
	} else
		goto st382;
	goto st0;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	switch( (*p) ) {
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st383;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st383;
	} else
		goto st383;
	goto st0;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
	switch( (*p) ) {
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st384;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st384;
	} else
		goto st384;
	goto st0;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
	switch( (*p) ) {
		case 58: goto st385;
		case 93: goto st495;
	}
	goto st0;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st386;
		case 49: goto st403;
		case 50: goto st406;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st409;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st410;
	} else
		goto st410;
	goto st0;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st387;
	} else
		goto st387;
	goto st0;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	switch( (*p) ) {
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st388;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st388;
	} else
		goto st388;
	goto st0;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
	switch( (*p) ) {
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st389;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st389;
	} else
		goto st389;
	goto st0;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	switch( (*p) ) {
		case 58: goto st390;
		case 93: goto st495;
	}
	goto st0;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
	switch( (*p) ) {
		case 2: goto st287;
		case 48: goto st391;
		case 49: goto st395;
		case 50: goto st398;
	}
	if ( (*p) < 65 ) {
		if ( 51 <= (*p) && (*p) <= 57 )
			goto st401;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st402;
	} else
		goto st402;
	goto st0;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st392;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st392;
	} else
		goto st392;
	goto st0;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
	switch( (*p) ) {
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st393;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st393;
	} else
		goto st393;
	goto st0;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
	switch( (*p) ) {
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st394;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st394;
	} else
		goto st394;
	goto st0;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
	switch( (*p) ) {
		case 58: goto st329;
		case 93: goto st495;
	}
	goto st0;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st396;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st392;
	} else
		goto st392;
	goto st0;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st397;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st393;
	} else
		goto st393;
	goto st0;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st394;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st394;
	} else
		goto st394;
	goto st0;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st400;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st399;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st392;
	} else
		goto st392;
	goto st0;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st393;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st393;
	} else
		goto st393;
	goto st0;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st397;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st393;
		} else if ( (*p) >= 65 )
			goto st393;
	} else
		goto st393;
	goto st0;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st399;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st392;
	} else
		goto st392;
	goto st0;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
	switch( (*p) ) {
		case 58: goto st329;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st392;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st392;
	} else
		goto st392;
	goto st0;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st404;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st387;
	} else
		goto st387;
	goto st0;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st405;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st388;
	} else
		goto st388;
	goto st0;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st389;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st389;
	} else
		goto st389;
	goto st0;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st408;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st407;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st387;
	} else
		goto st387;
	goto st0;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st388;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st388;
	} else
		goto st388;
	goto st0;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st405;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st388;
		} else if ( (*p) >= 65 )
			goto st388;
	} else
		goto st388;
	goto st0;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st407;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st387;
	} else
		goto st387;
	goto st0;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	switch( (*p) ) {
		case 58: goto st390;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st387;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st387;
	} else
		goto st387;
	goto st0;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st412;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st382;
	} else
		goto st382;
	goto st0;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st413;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st383;
	} else
		goto st383;
	goto st0;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st384;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st384;
	} else
		goto st384;
	goto st0;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st416;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st415;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st382;
	} else
		goto st382;
	goto st0;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st383;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st383;
	} else
		goto st383;
	goto st0;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st413;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st383;
		} else if ( (*p) >= 65 )
			goto st383;
	} else
		goto st383;
	goto st0;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st415;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st382;
	} else
		goto st382;
	goto st0;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
	switch( (*p) ) {
		case 58: goto st385;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st382;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st382;
	} else
		goto st382;
	goto st0;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st420;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st377;
	} else
		goto st377;
	goto st0;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st421;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st378;
	} else
		goto st378;
	goto st0;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st379;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st379;
	} else
		goto st379;
	goto st0;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st424;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st423;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st377;
	} else
		goto st377;
	goto st0;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st378;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st378;
	} else
		goto st378;
	goto st0;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st421;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st378;
		} else if ( (*p) >= 65 )
			goto st378;
	} else
		goto st378;
	goto st0;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st423;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st377;
	} else
		goto st377;
	goto st0;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	switch( (*p) ) {
		case 58: goto st380;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st377;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st377;
	} else
		goto st377;
	goto st0;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st428;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st372;
	} else
		goto st372;
	goto st0;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st429;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st373;
	} else
		goto st373;
	goto st0;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st374;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st374;
	} else
		goto st374;
	goto st0;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st432;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st431;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st372;
	} else
		goto st372;
	goto st0;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st373;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st373;
	} else
		goto st373;
	goto st0;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st429;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st373;
		} else if ( (*p) >= 65 )
			goto st373;
	} else
		goto st373;
	goto st0;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st431;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st372;
	} else
		goto st372;
	goto st0;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 58: goto st375;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st372;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st372;
	} else
		goto st372;
	goto st0;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st436;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st367;
	} else
		goto st367;
	goto st0;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st437;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st368;
	} else
		goto st368;
	goto st0;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st369;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st369;
	} else
		goto st369;
	goto st0;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
	switch( (*p) ) {
		case 46: goto st290;
		case 53: goto st440;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st439;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st367;
	} else
		goto st367;
	goto st0;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st368;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st368;
	} else
		goto st368;
	goto st0;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 54 ) {
		if ( 48 <= (*p) && (*p) <= 53 )
			goto st437;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st368;
		} else if ( (*p) >= 65 )
			goto st368;
	} else
		goto st368;
	goto st0;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
	switch( (*p) ) {
		case 46: goto st290;
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st439;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st367;
	} else
		goto st367;
	goto st0;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 58: goto st370;
		case 93: goto st495;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st367;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st367;
	} else
		goto st367;
	goto st0;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st444;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st444;
	} else
		goto st444;
	goto st0;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	if ( (*p) == 46 )
		goto st445;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st444;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st444;
	} else
		goto st444;
	goto st0;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	switch( (*p) ) {
		case 33: goto st446;
		case 36: goto st446;
		case 61: goto st446;
		case 95: goto st446;
		case 126: goto st446;
	}
	if ( (*p) < 48 ) {
		if ( 38 <= (*p) && (*p) <= 46 )
			goto st446;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st446;
		} else if ( (*p) >= 65 )
			goto st446;
	} else
		goto st446;
	goto st0;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	switch( (*p) ) {
		case 33: goto st446;
		case 36: goto st446;
		case 61: goto st446;
		case 93: goto st495;
		case 95: goto st446;
		case 126: goto st446;
	}
	if ( (*p) < 48 ) {
		if ( 38 <= (*p) && (*p) <= 46 )
			goto st446;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st446;
		} else if ( (*p) >= 65 )
			goto st446;
	} else
		goto st446;
	goto st0;
tr566:
#line 17 "uri.rl"
	{ mark = p; }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 9418 "uri.cc"
	switch( (*p) ) {
		case 33: goto st504;
		case 35: goto tr578;
		case 37: goto st252;
		case 47: goto tr579;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr581;
		case 64: goto tr563;
		case 95: goto st504;
		case 126: goto st504;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st527;
		} else
			goto st504;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st504;
	} else
		goto st504;
	goto st460;
tr537:
#line 17 "uri.rl"
	{ mark = p; }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 9460 "uri.cc"
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st529;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st502;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st502;
	} else
		goto st0;
	goto st460;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
	switch( (*p) ) {
		case 2: goto st232;
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 47: goto tr560;
		case 48: goto st530;
		case 49: goto st538;
		case 50: goto st540;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st539;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st531;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st502;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st502;
	} else
		goto st0;
	goto st460;
st531:
	if ( ++p == pe )
		goto _test_eof531;
case 531:
	switch( (*p) ) {
		case 2: goto st236;
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 47: goto tr560;
		case 48: goto st532;
		case 49: goto st534;
		case 50: goto st536;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st535;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st532:
	if ( ++p == pe )
		goto _test_eof532;
case 532:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st533;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st502;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st502;
	} else
		goto st0;
	goto st460;
st533:
	if ( ++p == pe )
		goto _test_eof533;
case 533:
	switch( (*p) ) {
		case 2: goto st240;
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st502;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st502;
	} else
		goto st0;
	goto st460;
st534:
	if ( ++p == pe )
		goto _test_eof534;
case 534:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st533;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st535;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st535:
	if ( ++p == pe )
		goto _test_eof535;
case 535:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st533;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st532;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st536:
	if ( ++p == pe )
		goto _test_eof536;
case 536:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st533;
		case 47: goto tr560;
		case 53: goto st537;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st532;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st537:
	if ( ++p == pe )
		goto _test_eof537;
case 537:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st533;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st532;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st538:
	if ( ++p == pe )
		goto _test_eof538;
case 538:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st531;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st539;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st539:
	if ( ++p == pe )
		goto _test_eof539;
case 539:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st531;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st530;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st540:
	if ( ++p == pe )
		goto _test_eof540;
case 540:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st531;
		case 47: goto tr560;
		case 53: goto st541;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st530;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st541:
	if ( ++p == pe )
		goto _test_eof541;
case 541:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st531;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st530;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
tr538:
#line 17 "uri.rl"
	{ mark = p; }
	goto st542;
st542:
	if ( ++p == pe )
		goto _test_eof542;
case 542:
#line 9995 "uri.cc"
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st529;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st543;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
tr540:
#line 17 "uri.rl"
	{ mark = p; }
	goto st543;
st543:
	if ( ++p == pe )
		goto _test_eof543;
case 543:
#line 10039 "uri.cc"
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st529;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st528;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
tr539:
#line 17 "uri.rl"
	{ mark = p; }
	goto st544;
st544:
	if ( ++p == pe )
		goto _test_eof544;
case 544:
#line 10083 "uri.cc"
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st529;
		case 47: goto tr560;
		case 53: goto st545;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st528;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
st545:
	if ( ++p == pe )
		goto _test_eof545;
case 545:
	switch( (*p) ) {
		case 33: goto st502;
		case 35: goto tr558;
		case 37: goto st250;
		case 46: goto st529;
		case 47: goto tr560;
		case 58: goto tr561;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr562;
		case 64: goto tr563;
		case 95: goto st502;
		case 126: goto st502;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st528;
		} else
			goto st502;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st502;
	} else
		goto st502;
	goto st460;
tr462:
#line 17 "uri.rl"
	{ mark = p; }
	goto st546;
st546:
	if ( ++p == pe )
		goto _test_eof546;
case 546:
#line 10167 "uri.cc"
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st547;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st467;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st467;
	} else
		goto st0;
	goto st454;
st547:
	if ( ++p == pe )
		goto _test_eof547;
case 547:
	switch( (*p) ) {
		case 2: goto st11;
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 47: goto tr483;
		case 48: goto st548;
		case 49: goto st556;
		case 50: goto st558;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st557;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st548:
	if ( ++p == pe )
		goto _test_eof548;
case 548:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st549;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st467;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st467;
	} else
		goto st0;
	goto st454;
st549:
	if ( ++p == pe )
		goto _test_eof549;
case 549:
	switch( (*p) ) {
		case 2: goto st15;
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 47: goto tr483;
		case 48: goto st550;
		case 49: goto st552;
		case 50: goto st554;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st553;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st550:
	if ( ++p == pe )
		goto _test_eof550;
case 550:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st551;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st467;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st467;
	} else
		goto st0;
	goto st454;
st551:
	if ( ++p == pe )
		goto _test_eof551;
case 551:
	switch( (*p) ) {
		case 2: goto st19;
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st467;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st467;
	} else
		goto st0;
	goto st454;
st552:
	if ( ++p == pe )
		goto _test_eof552;
case 552:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st551;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st553;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st553:
	if ( ++p == pe )
		goto _test_eof553;
case 553:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st551;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st550;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st554:
	if ( ++p == pe )
		goto _test_eof554;
case 554:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st551;
		case 47: goto tr483;
		case 53: goto st555;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st550;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st555:
	if ( ++p == pe )
		goto _test_eof555;
case 555:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st551;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st550;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st556:
	if ( ++p == pe )
		goto _test_eof556;
case 556:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st549;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st557;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st557:
	if ( ++p == pe )
		goto _test_eof557;
case 557:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st549;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st548;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st558:
	if ( ++p == pe )
		goto _test_eof558;
case 558:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st549;
		case 47: goto tr483;
		case 53: goto st559;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st548;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st559:
	if ( ++p == pe )
		goto _test_eof559;
case 559:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st549;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st548;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
tr463:
#line 17 "uri.rl"
	{ mark = p; }
	goto st560;
st560:
	if ( ++p == pe )
		goto _test_eof560;
case 560:
#line 10702 "uri.cc"
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st547;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st561;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
tr465:
#line 17 "uri.rl"
	{ mark = p; }
	goto st561;
st561:
	if ( ++p == pe )
		goto _test_eof561;
case 561:
#line 10746 "uri.cc"
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st547;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st546;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
tr464:
#line 17 "uri.rl"
	{ mark = p; }
	goto st562;
st562:
	if ( ++p == pe )
		goto _test_eof562;
case 562:
#line 10790 "uri.cc"
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st547;
		case 47: goto tr483;
		case 53: goto st563;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st546;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
st563:
	if ( ++p == pe )
		goto _test_eof563;
case 563:
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 46: goto st547;
		case 47: goto tr483;
		case 58: goto tr499;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st546;
		} else
			goto st467;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st467;
	} else
		goto st467;
	goto st454;
tr469:
#line 16 "uri.rl"
	{ mark = p; }
#line 17 "uri.rl"
	{ mark = p; }
	goto st564;
st564:
	if ( ++p == pe )
		goto _test_eof564;
case 564:
#line 10876 "uri.cc"
	switch( (*p) ) {
		case 33: goto st467;
		case 35: goto tr482;
		case 37: goto st31;
		case 43: goto st564;
		case 47: goto tr483;
		case 58: goto tr632;
		case 59: goto st467;
		case 60: goto st0;
		case 61: goto st467;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr500;
		case 95: goto st467;
		case 126: goto st467;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 44 )
				goto st467;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st564;
	} else
		goto st564;
	goto st454;
tr632:
#line 20 "uri.rl"
	{
        if(mark)
            uri->setScheme(std::string(mark, p - mark));
        mark = NULL;
    }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st565;
st565:
	if ( ++p == pe )
		goto _test_eof565;
case 565:
#line 10928 "uri.cc"
	switch( (*p) ) {
		case 33: goto st469;
		case 35: goto tr489;
		case 37: goto st33;
		case 47: goto tr633;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr492;
		case 64: goto tr500;
		case 95: goto st469;
		case 126: goto st469;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr502;
		} else
			goto st469;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st469;
	} else
		goto st469;
	goto st454;
tr633:
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	goto st566;
st566:
	if ( ++p == pe )
		goto _test_eof566;
case 566:
#line 10976 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr486;
		case 37: goto st21;
		case 47: goto st567;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr488;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 91 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 94 ) {
		if ( 123 <= (*p) && (*p) <= 125 )
			goto st0;
	} else
		goto st0;
	goto st460;
st567:
	if ( ++p == pe )
		goto _test_eof567;
case 567:
	switch( (*p) ) {
		case 2: goto tr457;
		case 33: goto tr635;
		case 35: goto tr459;
		case 37: goto tr636;
		case 47: goto tr505;
		case 48: goto tr637;
		case 49: goto tr638;
		case 50: goto tr639;
		case 58: goto tr641;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr467;
		case 64: goto tr642;
		case 91: goto tr470;
		case 95: goto tr635;
		case 126: goto tr635;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto tr640;
		} else
			goto tr635;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 92 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto tr635;
	} else
		goto tr635;
	goto st460;
tr635:
#line 17 "uri.rl"
	{ mark = p; }
	goto st568;
st568:
	if ( ++p == pe )
		goto _test_eof568;
case 568:
#line 11048 "uri.cc"
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st568;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st568;
	} else
		goto st0;
	goto st460;
tr636:
#line 17 "uri.rl"
	{ mark = p; }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 11085 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st448;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st448;
	} else
		goto st448;
	goto st0;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st568;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st568;
	} else
		goto st568;
	goto st0;
tr641:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st569;
tr644:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st569;
st569:
	if ( ++p == pe )
		goto _test_eof569;
case 569:
#line 11128 "uri.cc"
	switch( (*p) ) {
		case 33: goto st570;
		case 35: goto tr489;
		case 37: goto st449;
		case 47: goto tr490;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr492;
		case 64: goto tr645;
		case 95: goto st570;
		case 126: goto st570;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr647;
		} else
			goto st570;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st570;
	} else
		goto st570;
	goto st460;
st570:
	if ( ++p == pe )
		goto _test_eof570;
case 570:
	switch( (*p) ) {
		case 33: goto st570;
		case 35: goto tr486;
		case 37: goto st449;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr488;
		case 64: goto tr645;
		case 95: goto st570;
		case 126: goto st570;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 46 )
				goto st570;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st570;
	} else
		goto st570;
	goto st460;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st450;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st450;
	} else
		goto st450;
	goto st0;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st570;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st570;
	} else
		goto st570;
	goto st0;
tr642:
#line 17 "uri.rl"
	{ mark = p; }
#line 35 "uri.rl"
	{
        if(mark)
            uri->setUser(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st571;
tr645:
#line 35 "uri.rl"
	{
        if(mark)
            uri->setUser(std::string(mark, p - mark));
        mark = NULL;
    }
	goto st571;
st571:
	if ( ++p == pe )
		goto _test_eof571;
case 571:
#line 11243 "uri.cc"
	switch( (*p) ) {
		case 2: goto tr457;
		case 33: goto tr648;
		case 35: goto tr459;
		case 37: goto tr649;
		case 47: goto tr505;
		case 48: goto tr650;
		case 49: goto tr651;
		case 50: goto tr652;
		case 58: goto tr654;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr467;
		case 91: goto tr470;
		case 95: goto tr648;
		case 126: goto tr648;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto tr653;
		} else
			goto tr648;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 92 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto tr648;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto tr648;
		} else
			goto st0;
	} else
		goto tr648;
	goto st460;
tr648:
#line 17 "uri.rl"
	{ mark = p; }
	goto st572;
st572:
	if ( ++p == pe )
		goto _test_eof572;
case 572:
#line 11293 "uri.cc"
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st572;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st572;
	} else
		goto st572;
	goto st460;
tr649:
#line 17 "uri.rl"
	{ mark = p; }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 11332 "uri.cc"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st452;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st452;
	} else
		goto st452;
	goto st0;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st572;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st572;
	} else
		goto st572;
	goto st0;
tr654:
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st573;
tr656:
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	goto st573;
st573:
	if ( ++p == pe )
		goto _test_eof573;
case 573:
#line 11375 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr489;
		case 37: goto st21;
		case 47: goto tr490;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr492;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 48 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto tr657;
	goto st460;
tr657:
#line 17 "uri.rl"
	{ mark = p; }
	goto st574;
st574:
	if ( ++p == pe )
		goto _test_eof574;
case 574:
#line 11407 "uri.cc"
	switch( (*p) ) {
		case 34: goto st0;
		case 35: goto tr493;
		case 37: goto st21;
		case 47: goto tr494;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr496;
		case 96: goto st0;
		case 127: goto st0;
	}
	if ( (*p) < 48 ) {
		if ( 0 <= (*p) && (*p) <= 32 )
			goto st0;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 94 ) {
			if ( 123 <= (*p) && (*p) <= 125 )
				goto st0;
		} else if ( (*p) >= 91 )
			goto st0;
	} else
		goto st574;
	goto st460;
tr650:
#line 17 "uri.rl"
	{ mark = p; }
	goto st575;
st575:
	if ( ++p == pe )
		goto _test_eof575;
case 575:
#line 11439 "uri.cc"
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st576;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st572;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st572;
	} else
		goto st572;
	goto st460;
st576:
	if ( ++p == pe )
		goto _test_eof576;
case 576:
	switch( (*p) ) {
		case 2: goto st11;
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 47: goto tr483;
		case 48: goto st577;
		case 49: goto st585;
		case 50: goto st587;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st586;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st577:
	if ( ++p == pe )
		goto _test_eof577;
case 577:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st578;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st572;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st572;
	} else
		goto st572;
	goto st460;
st578:
	if ( ++p == pe )
		goto _test_eof578;
case 578:
	switch( (*p) ) {
		case 2: goto st15;
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 47: goto tr483;
		case 48: goto st579;
		case 49: goto st581;
		case 50: goto st583;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st582;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st579:
	if ( ++p == pe )
		goto _test_eof579;
case 579:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st580;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st572;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st572;
	} else
		goto st572;
	goto st460;
st580:
	if ( ++p == pe )
		goto _test_eof580;
case 580:
	switch( (*p) ) {
		case 2: goto st19;
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 61 )
				goto st572;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st572;
	} else
		goto st572;
	goto st460;
st581:
	if ( ++p == pe )
		goto _test_eof581;
case 581:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st580;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st582;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st582:
	if ( ++p == pe )
		goto _test_eof582;
case 582:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st580;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st579;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st583:
	if ( ++p == pe )
		goto _test_eof583;
case 583:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st580;
		case 47: goto tr483;
		case 53: goto st584;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st579;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st584:
	if ( ++p == pe )
		goto _test_eof584;
case 584:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st580;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st579;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st585:
	if ( ++p == pe )
		goto _test_eof585;
case 585:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st578;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st586;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st586:
	if ( ++p == pe )
		goto _test_eof586;
case 586:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st578;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st577;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st587:
	if ( ++p == pe )
		goto _test_eof587;
case 587:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st578;
		case 47: goto tr483;
		case 53: goto st588;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st577;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st588:
	if ( ++p == pe )
		goto _test_eof588;
case 588:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st578;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st577;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
tr651:
#line 17 "uri.rl"
	{ mark = p; }
	goto st589;
st589:
	if ( ++p == pe )
		goto _test_eof589;
case 589:
#line 12002 "uri.cc"
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st576;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st590;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
tr653:
#line 17 "uri.rl"
	{ mark = p; }
	goto st590;
st590:
	if ( ++p == pe )
		goto _test_eof590;
case 590:
#line 12048 "uri.cc"
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st576;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st575;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
tr652:
#line 17 "uri.rl"
	{ mark = p; }
	goto st591;
st591:
	if ( ++p == pe )
		goto _test_eof591;
case 591:
#line 12094 "uri.cc"
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st576;
		case 47: goto tr483;
		case 53: goto st592;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st575;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
st592:
	if ( ++p == pe )
		goto _test_eof592;
case 592:
	switch( (*p) ) {
		case 33: goto st572;
		case 35: goto tr482;
		case 37: goto st451;
		case 46: goto st576;
		case 47: goto tr483;
		case 58: goto tr656;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 95: goto st572;
		case 126: goto st572;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st575;
		} else
			goto st572;
	} else if ( (*p) > 61 ) {
		if ( (*p) < 91 ) {
			if ( 65 <= (*p) && (*p) <= 90 )
				goto st572;
		} else if ( (*p) > 96 ) {
			if ( (*p) > 122 ) {
				if ( 123 <= (*p) )
					goto st0;
			} else if ( (*p) >= 97 )
				goto st572;
		} else
			goto st0;
	} else
		goto st572;
	goto st460;
tr647:
#line 17 "uri.rl"
	{ mark = p; }
	goto st593;
st593:
	if ( ++p == pe )
		goto _test_eof593;
case 593:
#line 12182 "uri.cc"
	switch( (*p) ) {
		case 33: goto st570;
		case 35: goto tr493;
		case 37: goto st449;
		case 47: goto tr494;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr496;
		case 64: goto tr645;
		case 95: goto st570;
		case 126: goto st570;
	}
	if ( (*p) < 58 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st593;
		} else
			goto st570;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st570;
	} else
		goto st570;
	goto st460;
tr637:
#line 17 "uri.rl"
	{ mark = p; }
	goto st594;
st594:
	if ( ++p == pe )
		goto _test_eof594;
case 594:
#line 12224 "uri.cc"
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st595;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st568;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st568;
	} else
		goto st0;
	goto st460;
st595:
	if ( ++p == pe )
		goto _test_eof595;
case 595:
	switch( (*p) ) {
		case 2: goto st11;
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 47: goto tr483;
		case 48: goto st596;
		case 49: goto st604;
		case 50: goto st606;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st605;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st596:
	if ( ++p == pe )
		goto _test_eof596;
case 596:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st597;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st568;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st568;
	} else
		goto st0;
	goto st460;
st597:
	if ( ++p == pe )
		goto _test_eof597;
case 597:
	switch( (*p) ) {
		case 2: goto st15;
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 47: goto tr483;
		case 48: goto st598;
		case 49: goto st600;
		case 50: goto st602;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 46 ) {
			if ( 51 <= (*p) && (*p) <= 57 )
				goto st601;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st598:
	if ( ++p == pe )
		goto _test_eof598;
case 598:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st599;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st568;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st568;
	} else
		goto st0;
	goto st460;
st599:
	if ( ++p == pe )
		goto _test_eof599;
case 599:
	switch( (*p) ) {
		case 2: goto st19;
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 91 ) {
		if ( (*p) > 34 ) {
			if ( 36 <= (*p) && (*p) <= 90 )
				goto st568;
		} else if ( (*p) >= 0 )
			goto st0;
	} else if ( (*p) > 96 ) {
		if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else if ( (*p) >= 97 )
			goto st568;
	} else
		goto st0;
	goto st460;
st600:
	if ( ++p == pe )
		goto _test_eof600;
case 600:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st599;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st601;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st601:
	if ( ++p == pe )
		goto _test_eof601;
case 601:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st599;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st598;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st602:
	if ( ++p == pe )
		goto _test_eof602;
case 602:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st599;
		case 47: goto tr483;
		case 53: goto st603;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st598;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st603:
	if ( ++p == pe )
		goto _test_eof603;
case 603:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st599;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st598;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st604:
	if ( ++p == pe )
		goto _test_eof604;
case 604:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st597;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st605;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st605:
	if ( ++p == pe )
		goto _test_eof605;
case 605:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st597;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st596;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st606:
	if ( ++p == pe )
		goto _test_eof606;
case 606:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st597;
		case 47: goto tr483;
		case 53: goto st607;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st596;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st607:
	if ( ++p == pe )
		goto _test_eof607;
case 607:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st597;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st596;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
tr638:
#line 17 "uri.rl"
	{ mark = p; }
	goto st608;
st608:
	if ( ++p == pe )
		goto _test_eof608;
case 608:
#line 12759 "uri.cc"
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st595;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st609;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
tr640:
#line 17 "uri.rl"
	{ mark = p; }
	goto st609;
st609:
	if ( ++p == pe )
		goto _test_eof609;
case 609:
#line 12803 "uri.cc"
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st595;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st594;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
tr639:
#line 17 "uri.rl"
	{ mark = p; }
	goto st610;
st610:
	if ( ++p == pe )
		goto _test_eof610;
case 610:
#line 12847 "uri.cc"
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st595;
		case 47: goto tr483;
		case 53: goto st611;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 59 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st594;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
st611:
	if ( ++p == pe )
		goto _test_eof611;
case 611:
	switch( (*p) ) {
		case 33: goto st568;
		case 35: goto tr482;
		case 37: goto st447;
		case 46: goto st595;
		case 47: goto tr483;
		case 58: goto tr644;
		case 60: goto st0;
		case 62: goto st0;
		case 63: goto tr485;
		case 64: goto tr645;
		case 95: goto st568;
		case 126: goto st568;
	}
	if ( (*p) < 54 ) {
		if ( (*p) < 36 ) {
			if ( 0 <= (*p) && (*p) <= 34 )
				goto st0;
		} else if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 53 )
				goto st594;
		} else
			goto st568;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st0;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) )
				goto st0;
		} else
			goto st568;
	} else
		goto st568;
	goto st460;
	}
	_test_eof454: cs = 454; goto _test_eof; 
	_test_eof455: cs = 455; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
	_test_eof476: cs = 476; goto _test_eof; 
	_test_eof477: cs = 477; goto _test_eof; 
	_test_eof478: cs = 478; goto _test_eof; 
	_test_eof479: cs = 479; goto _test_eof; 
	_test_eof480: cs = 480; goto _test_eof; 
	_test_eof481: cs = 481; goto _test_eof; 
	_test_eof482: cs = 482; goto _test_eof; 
	_test_eof483: cs = 483; goto _test_eof; 
	_test_eof484: cs = 484; goto _test_eof; 
	_test_eof485: cs = 485; goto _test_eof; 
	_test_eof486: cs = 486; goto _test_eof; 
	_test_eof487: cs = 487; goto _test_eof; 
	_test_eof488: cs = 488; goto _test_eof; 
	_test_eof489: cs = 489; goto _test_eof; 
	_test_eof490: cs = 490; goto _test_eof; 
	_test_eof491: cs = 491; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof492: cs = 492; goto _test_eof; 
	_test_eof493: cs = 493; goto _test_eof; 
	_test_eof494: cs = 494; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof495: cs = 495; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof497: cs = 497; goto _test_eof; 
	_test_eof498: cs = 498; goto _test_eof; 
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof500: cs = 500; goto _test_eof; 
	_test_eof501: cs = 501; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof502: cs = 502; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof503: cs = 503; goto _test_eof; 
	_test_eof504: cs = 504; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof505: cs = 505; goto _test_eof; 
	_test_eof506: cs = 506; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof255: cs = 255; goto _test_eof; 
	_test_eof507: cs = 507; goto _test_eof; 
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
	_test_eof515: cs = 515; goto _test_eof; 
	_test_eof516: cs = 516; goto _test_eof; 
	_test_eof517: cs = 517; goto _test_eof; 
	_test_eof518: cs = 518; goto _test_eof; 
	_test_eof519: cs = 519; goto _test_eof; 
	_test_eof520: cs = 520; goto _test_eof; 
	_test_eof521: cs = 521; goto _test_eof; 
	_test_eof522: cs = 522; goto _test_eof; 
	_test_eof523: cs = 523; goto _test_eof; 
	_test_eof524: cs = 524; goto _test_eof; 
	_test_eof525: cs = 525; goto _test_eof; 
	_test_eof526: cs = 526; goto _test_eof; 
	_test_eof256: cs = 256; goto _test_eof; 
	_test_eof257: cs = 257; goto _test_eof; 
	_test_eof258: cs = 258; goto _test_eof; 
	_test_eof259: cs = 259; goto _test_eof; 
	_test_eof260: cs = 260; goto _test_eof; 
	_test_eof261: cs = 261; goto _test_eof; 
	_test_eof262: cs = 262; goto _test_eof; 
	_test_eof263: cs = 263; goto _test_eof; 
	_test_eof264: cs = 264; goto _test_eof; 
	_test_eof265: cs = 265; goto _test_eof; 
	_test_eof266: cs = 266; goto _test_eof; 
	_test_eof267: cs = 267; goto _test_eof; 
	_test_eof268: cs = 268; goto _test_eof; 
	_test_eof269: cs = 269; goto _test_eof; 
	_test_eof270: cs = 270; goto _test_eof; 
	_test_eof271: cs = 271; goto _test_eof; 
	_test_eof272: cs = 272; goto _test_eof; 
	_test_eof273: cs = 273; goto _test_eof; 
	_test_eof274: cs = 274; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 
	_test_eof336: cs = 336; goto _test_eof; 
	_test_eof337: cs = 337; goto _test_eof; 
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
	_test_eof353: cs = 353; goto _test_eof; 
	_test_eof354: cs = 354; goto _test_eof; 
	_test_eof355: cs = 355; goto _test_eof; 
	_test_eof356: cs = 356; goto _test_eof; 
	_test_eof357: cs = 357; goto _test_eof; 
	_test_eof358: cs = 358; goto _test_eof; 
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
	_test_eof380: cs = 380; goto _test_eof; 
	_test_eof381: cs = 381; goto _test_eof; 
	_test_eof382: cs = 382; goto _test_eof; 
	_test_eof383: cs = 383; goto _test_eof; 
	_test_eof384: cs = 384; goto _test_eof; 
	_test_eof385: cs = 385; goto _test_eof; 
	_test_eof386: cs = 386; goto _test_eof; 
	_test_eof387: cs = 387; goto _test_eof; 
	_test_eof388: cs = 388; goto _test_eof; 
	_test_eof389: cs = 389; goto _test_eof; 
	_test_eof390: cs = 390; goto _test_eof; 
	_test_eof391: cs = 391; goto _test_eof; 
	_test_eof392: cs = 392; goto _test_eof; 
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
	_test_eof401: cs = 401; goto _test_eof; 
	_test_eof402: cs = 402; goto _test_eof; 
	_test_eof403: cs = 403; goto _test_eof; 
	_test_eof404: cs = 404; goto _test_eof; 
	_test_eof405: cs = 405; goto _test_eof; 
	_test_eof406: cs = 406; goto _test_eof; 
	_test_eof407: cs = 407; goto _test_eof; 
	_test_eof408: cs = 408; goto _test_eof; 
	_test_eof409: cs = 409; goto _test_eof; 
	_test_eof410: cs = 410; goto _test_eof; 
	_test_eof411: cs = 411; goto _test_eof; 
	_test_eof412: cs = 412; goto _test_eof; 
	_test_eof413: cs = 413; goto _test_eof; 
	_test_eof414: cs = 414; goto _test_eof; 
	_test_eof415: cs = 415; goto _test_eof; 
	_test_eof416: cs = 416; goto _test_eof; 
	_test_eof417: cs = 417; goto _test_eof; 
	_test_eof418: cs = 418; goto _test_eof; 
	_test_eof419: cs = 419; goto _test_eof; 
	_test_eof420: cs = 420; goto _test_eof; 
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof441: cs = 441; goto _test_eof; 
	_test_eof442: cs = 442; goto _test_eof; 
	_test_eof443: cs = 443; goto _test_eof; 
	_test_eof444: cs = 444; goto _test_eof; 
	_test_eof445: cs = 445; goto _test_eof; 
	_test_eof446: cs = 446; goto _test_eof; 
	_test_eof527: cs = 527; goto _test_eof; 
	_test_eof528: cs = 528; goto _test_eof; 
	_test_eof529: cs = 529; goto _test_eof; 
	_test_eof530: cs = 530; goto _test_eof; 
	_test_eof531: cs = 531; goto _test_eof; 
	_test_eof532: cs = 532; goto _test_eof; 
	_test_eof533: cs = 533; goto _test_eof; 
	_test_eof534: cs = 534; goto _test_eof; 
	_test_eof535: cs = 535; goto _test_eof; 
	_test_eof536: cs = 536; goto _test_eof; 
	_test_eof537: cs = 537; goto _test_eof; 
	_test_eof538: cs = 538; goto _test_eof; 
	_test_eof539: cs = 539; goto _test_eof; 
	_test_eof540: cs = 540; goto _test_eof; 
	_test_eof541: cs = 541; goto _test_eof; 
	_test_eof542: cs = 542; goto _test_eof; 
	_test_eof543: cs = 543; goto _test_eof; 
	_test_eof544: cs = 544; goto _test_eof; 
	_test_eof545: cs = 545; goto _test_eof; 
	_test_eof546: cs = 546; goto _test_eof; 
	_test_eof547: cs = 547; goto _test_eof; 
	_test_eof548: cs = 548; goto _test_eof; 
	_test_eof549: cs = 549; goto _test_eof; 
	_test_eof550: cs = 550; goto _test_eof; 
	_test_eof551: cs = 551; goto _test_eof; 
	_test_eof552: cs = 552; goto _test_eof; 
	_test_eof553: cs = 553; goto _test_eof; 
	_test_eof554: cs = 554; goto _test_eof; 
	_test_eof555: cs = 555; goto _test_eof; 
	_test_eof556: cs = 556; goto _test_eof; 
	_test_eof557: cs = 557; goto _test_eof; 
	_test_eof558: cs = 558; goto _test_eof; 
	_test_eof559: cs = 559; goto _test_eof; 
	_test_eof560: cs = 560; goto _test_eof; 
	_test_eof561: cs = 561; goto _test_eof; 
	_test_eof562: cs = 562; goto _test_eof; 
	_test_eof563: cs = 563; goto _test_eof; 
	_test_eof564: cs = 564; goto _test_eof; 
	_test_eof565: cs = 565; goto _test_eof; 
	_test_eof566: cs = 566; goto _test_eof; 
	_test_eof567: cs = 567; goto _test_eof; 
	_test_eof568: cs = 568; goto _test_eof; 
	_test_eof447: cs = 447; goto _test_eof; 
	_test_eof448: cs = 448; goto _test_eof; 
	_test_eof569: cs = 569; goto _test_eof; 
	_test_eof570: cs = 570; goto _test_eof; 
	_test_eof449: cs = 449; goto _test_eof; 
	_test_eof450: cs = 450; goto _test_eof; 
	_test_eof571: cs = 571; goto _test_eof; 
	_test_eof572: cs = 572; goto _test_eof; 
	_test_eof451: cs = 451; goto _test_eof; 
	_test_eof452: cs = 452; goto _test_eof; 
	_test_eof573: cs = 573; goto _test_eof; 
	_test_eof574: cs = 574; goto _test_eof; 
	_test_eof575: cs = 575; goto _test_eof; 
	_test_eof576: cs = 576; goto _test_eof; 
	_test_eof577: cs = 577; goto _test_eof; 
	_test_eof578: cs = 578; goto _test_eof; 
	_test_eof579: cs = 579; goto _test_eof; 
	_test_eof580: cs = 580; goto _test_eof; 
	_test_eof581: cs = 581; goto _test_eof; 
	_test_eof582: cs = 582; goto _test_eof; 
	_test_eof583: cs = 583; goto _test_eof; 
	_test_eof584: cs = 584; goto _test_eof; 
	_test_eof585: cs = 585; goto _test_eof; 
	_test_eof586: cs = 586; goto _test_eof; 
	_test_eof587: cs = 587; goto _test_eof; 
	_test_eof588: cs = 588; goto _test_eof; 
	_test_eof589: cs = 589; goto _test_eof; 
	_test_eof590: cs = 590; goto _test_eof; 
	_test_eof591: cs = 591; goto _test_eof; 
	_test_eof592: cs = 592; goto _test_eof; 
	_test_eof593: cs = 593; goto _test_eof; 
	_test_eof594: cs = 594; goto _test_eof; 
	_test_eof595: cs = 595; goto _test_eof; 
	_test_eof596: cs = 596; goto _test_eof; 
	_test_eof597: cs = 597; goto _test_eof; 
	_test_eof598: cs = 598; goto _test_eof; 
	_test_eof599: cs = 599; goto _test_eof; 
	_test_eof600: cs = 600; goto _test_eof; 
	_test_eof601: cs = 601; goto _test_eof; 
	_test_eof602: cs = 602; goto _test_eof; 
	_test_eof603: cs = 603; goto _test_eof; 
	_test_eof604: cs = 604; goto _test_eof; 
	_test_eof605: cs = 605; goto _test_eof; 
	_test_eof606: cs = 606; goto _test_eof; 
	_test_eof607: cs = 607; goto _test_eof; 
	_test_eof608: cs = 608; goto _test_eof; 
	_test_eof609: cs = 609; goto _test_eof; 
	_test_eof610: cs = 610; goto _test_eof; 
	_test_eof611: cs = 611; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 497: 
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	break;
	case 495: 
	case 498: 
	case 499: 
	case 500: 
	case 501: 
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	break;
	case 460: 
	case 493: 
	case 504: 
	case 566: 
	case 570: 
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 458: 
#line 94 "uri.rl"
	{
        uri->setQuery(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 456: 
#line 99 "uri.rl"
	{
        uri->setFrag(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 457: 
#line 16 "uri.rl"
	{ mark = p; }
#line 94 "uri.rl"
	{
        uri->setQuery(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 455: 
#line 16 "uri.rl"
	{ mark = p; }
#line 99 "uri.rl"
	{
        uri->setFrag(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 496: 
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	break;
	case 508: 
	case 527: 
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	break;
	case 502: 
	case 506: 
	case 509: 
	case 510: 
	case 511: 
	case 512: 
	case 513: 
	case 514: 
	case 515: 
	case 516: 
	case 517: 
	case 518: 
	case 519: 
	case 520: 
	case 521: 
	case 522: 
	case 523: 
	case 524: 
	case 525: 
	case 526: 
	case 528: 
	case 529: 
	case 530: 
	case 531: 
	case 532: 
	case 533: 
	case 534: 
	case 535: 
	case 536: 
	case 537: 
	case 538: 
	case 539: 
	case 540: 
	case 541: 
	case 542: 
	case 543: 
	case 544: 
	case 545: 
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	break;
	case 461: 
	case 468: 
	case 472: 
	case 565: 
	case 569: 
	case 573: 
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 453: 
	case 470: 
	case 567: 
	case 571: 
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 462: 
	case 473: 
	case 492: 
	case 574: 
	case 593: 
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 459: 
	case 463: 
	case 464: 
	case 465: 
	case 466: 
	case 467: 
	case 471: 
	case 474: 
	case 475: 
	case 476: 
	case 477: 
	case 478: 
	case 479: 
	case 480: 
	case 481: 
	case 482: 
	case 483: 
	case 484: 
	case 485: 
	case 486: 
	case 487: 
	case 488: 
	case 489: 
	case 490: 
	case 491: 
	case 546: 
	case 547: 
	case 548: 
	case 549: 
	case 550: 
	case 551: 
	case 552: 
	case 553: 
	case 554: 
	case 555: 
	case 556: 
	case 557: 
	case 558: 
	case 559: 
	case 560: 
	case 561: 
	case 562: 
	case 563: 
	case 564: 
	case 568: 
	case 572: 
	case 575: 
	case 576: 
	case 577: 
	case 578: 
	case 579: 
	case 580: 
	case 581: 
	case 582: 
	case 583: 
	case 584: 
	case 585: 
	case 586: 
	case 587: 
	case 588: 
	case 589: 
	case 590: 
	case 591: 
	case 592: 
	case 594: 
	case 595: 
	case 596: 
	case 597: 
	case 598: 
	case 599: 
	case 600: 
	case 601: 
	case 602: 
	case 603: 
	case 604: 
	case 605: 
	case 606: 
	case 607: 
	case 608: 
	case 609: 
	case 610: 
	case 611: 
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
	break;
	case 503: 
	case 507: 
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 29 "uri.rl"
	{
        if (p != mark)
            uri->setPort(atoi(mark));
        mark = NULL;
    }
	break;
	case 494: 
	case 505: 
#line 74 "uri.rl"
	{
        uri->setPath(std::string(mark, p - mark));
        mark = NULL;
    }
#line 17 "uri.rl"
	{ mark = p; }
#line 41 "uri.rl"
	{
        if (mark != NULL)
            uri->setHost(std::string(mark, p - mark));
    }
	break;
#line 13856 "uri.cc"
	}
	}

	_out: {}
	}

#line 131 "uri.rl"
    if(uri->getScheme().empty())
        uri->setScheme("http");
    if(cs == uri_parser_error)
        return nullptr;
    else if(cs >= uri_parser_first_final)
        return uri;
    return nullptr;
}

bool Uri::isDefaultPort() const {
    if(m_port == 0)
        return true;
    if(m_scheme == "http" || m_scheme == "ws")
        return m_port == 80;
    else if(m_scheme == "https" || m_scheme == "wss")
        return m_port == 443;
    return false;
}

uint32_t Uri::getPort() const {
    if(m_port)
        return m_port;
    if(m_scheme == "http" || m_scheme == "ws")
        return 80;
    else if(m_scheme == "https" || m_scheme == "wss")
        return 443;
    return m_port;
}

std::ostream& Uri::dump(std::ostream& os) const {
    os << m_scheme << (m_scheme.empty() ? "" : "://")
       << m_user   << (m_user.empty() ? "" : "@")
       << m_host   << (isDefaultPort() ? "" : ":" + std::to_string(m_port))
       << m_path   
       << (m_query.empty() ? "" : "?") << m_query  
       << (m_frag.empty() ? "" : "#")  << m_frag;
    return os;
}

std::string Uri::toString() const {
    std::stringstream ss;
    dump(ss);
    return ss.str();
}

Address::ptr Uri::getAddress() const {
    auto addr = Address::LookupAny(m_host);
    if(addr)
        addr->setPort(getPort());
    return addr;
}

}
