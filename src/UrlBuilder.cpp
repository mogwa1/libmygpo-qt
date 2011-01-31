/***************************************************************************
* This file is part of libmygpo-qt                                         *
* Copyright (c) 2010 - 2011 Stefan Derkits <stefan@derkits.at>             *
* Copyright (c) 2010 - 2011 Christian Wagner <christian.wagner86@gmx.at>   *
* Copyright (c) 2010 - 2011 Felix Winter <ixos01@gmail.com>                *
*                                                                          *
* This library is free software; you can redistribute it and/or            *
* modify it under the terms of the GNU Lesser General Public               *
* License as published by the Free Software Foundation; either             *
* version 2.1 of the License, or (at your option) any later version.       *
*                                                                          *
* This library is distributed in the hope that it will be useful,          *
* but WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU        *
* Lesser General Public License for more details.                          *
*                                                                          *
* You should have received a copy of the GNU Lesser General Public         *
* License along with this library; if not, write to the Free Software      *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 *
* USA                                                                      *
***************************************************************************/


#include "UrlBuilder.h"
#include "QString"

#include <QLatin1String>


using namespace mygpo;

const QString UrlBuilder::s_server = QLatin1String( "gpodder.net" );
const QString UrlBuilder::s_api2 = QLatin1String( "/api/2" );
const QString UrlBuilder::s_api1 = QLatin1String( "/api/1" );


QString UrlBuilder::getToplistUrl( uint i, Format f )
{
    QString numString = QString::number(( i == 0 ) ? 1 : i );
    return QLatin1String("http://") + s_server + QLatin1String( "/toplist/" ) + numString + UrlBuilder::getFormatExtension( f );
}

QString UrlBuilder::getSuggestionsUrl( uint i, Format f )
{
    QString numString = QString::number(( i == 0 ) ? 1 : i );
    return QLatin1String("http://") + s_server + QLatin1String( "/suggestions/" ) + numString + getFormatExtension( f );
}

QString UrlBuilder::getPodcastSearchUrl( const QString& query, Format f )
{
    return QLatin1String("http://") + s_server + QLatin1String( "/search" ) + getFormatExtension( f ) + QLatin1String( "?q=" ) + query;
}

QString UrlBuilder::getTopTagsUrl( uint i )
{
    QString numString = QString::number(( i == 0 ) ? 1 : i );
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/tags/" ) + numString + QLatin1String( ".json" );
}

QString UrlBuilder::getPodcastsOfTagUrl( const QString& tag, uint i )
{
    QString numString = QString::number(( i == 0 ) ? 1 : i );
    return  s_server + s_api2 + QLatin1String( "/tag/" ) + tag + QLatin1String( "/" ) + numString + QLatin1String( ".json" );
}

QString UrlBuilder::getPodcastDataUrl( const QString& url )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/data/podcast" ) + QLatin1String( ".json" ) + QLatin1String( "?url=" ) + url;
}

QString UrlBuilder::getEpisodeDataUrl( const QString& podcastUrl, const QString& episodeUrl )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/data/episode" ) + QLatin1String( ".json" ) + QLatin1String( "?podcast=" ) + podcastUrl + QLatin1String( "&url=" ) + episodeUrl;
}

QString UrlBuilder::getFavEpisodesUrl( const QString& username )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/favorites/" ) + username + QLatin1String( ".json" );
}


QString UrlBuilder::getAddRemoveSubUrl( const QString& username, const QString& deviceId )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/subscriptions/" ) + username + QLatin1String( "/" ) + deviceId + QLatin1String( ".json" );
}

QString UrlBuilder::getAccountSettingsUrl( const QString& username )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/settings/" ) + username + QLatin1String( "/account" ) + QLatin1String( ".json" );
}

QString UrlBuilder::getDeviceSettingsUrl( const QString& username, const QString& deviceId )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/settings/" ) + username + QLatin1String( "/device" ) + QLatin1String( ".json" ) + QLatin1String( "?device=" ) + deviceId;
}

QString UrlBuilder::getPodcastSettingsUrl( const QString& username, const QString& podcastUrl )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/settings/" ) + username + QLatin1String( "/podcast" ) + QLatin1String( ".json" ) + QLatin1String( "?podcast=" ) + podcastUrl;
}

QString UrlBuilder::getEpisodeSettingsUrl( const QString& username, const QString& podcastUrl, const QString& episodeUrl )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/settings/" ) + username + QLatin1String( "/episode" ) + QLatin1String( ".json" ) + QLatin1String( "?podcast=" ) + podcastUrl + QLatin1String( "&episode=" ) + episodeUrl;
}

QString UrlBuilder::getDeviceListUrl( const QString& username )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/devices/" ) + username + QLatin1String( ".json" ) ;
}

QString UrlBuilder::getDeviceUpdatesUrl( const QString& username, const QString& deviceId, qulonglong timestamp )
{
    QString numString = QString::number( timestamp < 0 ? 0 : timestamp );
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/updates/" ) + username + QLatin1String( "/" ) + deviceId + QLatin1String( ".json?since=" ) + numString;
}

QString UrlBuilder::getRenameDeviceUrl( const QString& username, const QString& deviceId )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/devices/" ) + username + QLatin1String( "/" ) + deviceId + QLatin1String( ".json" );
}

QString UrlBuilder::getEpisodeActionsUrl( const QString& username )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json" );
}

QString UrlBuilder::getEpisodeActionsUrlByPodcast( const QString& username, const QString& podcastUrl )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json?podcast=" ) + podcastUrl;
}

QString UrlBuilder::getEpisodeActionsUrlByDevice( const QString& username, const QString& deviceId )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json?device=" ) + deviceId;
}

QString UrlBuilder::getEpisodeActionsUrlByTimestamp( const QString& username, const qulonglong since )
{
    QString numString = QString::number( since );
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json?since=" ) + numString;
}

QString UrlBuilder::getEpisodeActionsUrlByPodcastAndTimestamp( const QString& username, const QString& podcastUrl, const qulonglong since )
{
    QString numString = QString::number( since );
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json?podcast=" ) + podcastUrl + QLatin1String( "&since=" ) + numString;
}

QString UrlBuilder::getEpisodeActionsUrlByDeviceAndTimestamp( const QString& username, const QString& deviceId, const qulonglong since )
{
    QString numString = QString::number( since );
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json?device=" ) + deviceId + QLatin1String( "&since=" ) + numString;
}

QString UrlBuilder::getEpisodeActionsUrlByPodcastAndAggregate( const QString& username, const QString& deviceId, const bool aggregated )
{
    QString agg;
    if( aggregated )
        agg = QLatin1String( "true" );
    else
        agg = QLatin1String( "false" );

    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json?podcast=" ) + deviceId + QLatin1String( "&aggregated=" ) + agg;
}

QString UrlBuilder::getUploadEpisodeActionsUrl( const QString& username )
{
    return QLatin1String("http://") + s_server + s_api2 + QLatin1String( "/episodes/" ) + username + QLatin1String( ".json" );
}

QString UrlBuilder::getFormatExtension( Format f )
{
    QString ret;
    switch( f )
    {
    case JSON:
        ret =  QString( QLatin1String( ".json" ) );
        break;
    case OPML:
        ret =  QString( QLatin1String( ".opml" ) );
        break;
    case TEXT:
        ret =  QString( QLatin1String( ".txt" ) );
        break;
    }
    return ret;
}
