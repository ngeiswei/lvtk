/*
   feature.hpp - Support file for writing LV2 plugins in C++
   Copyright (C) 2012 Michael Fisher <mfisher31@gmail.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 01222-1307  USA
*/
/**
   @headerfile lvtk/feature.hpp
   C++ convenience header for LV2 Feature handling.
   LV2 Version Support: lv2core 8.0 (2012-04-17) STABLE
*/

#ifndef LVTK_FEATURE_HPP
#define LVTK_FEATURE_HPP

#include <map>
#include <string>
#include <vector>

#include <lv2/lv2plug.in/ns/lv2core/lv2.h>

namespace lvtk {

   using std::map;
   using std::string;
   using std::vector;

   /** Typedef for the LV2_Feature type so we get it into the LV2 namespace. */
   typedef LV2_Feature Feature;

   /** Convenient typedef for a vector of Features. */
   typedef vector<const Feature*> FeatureVec;

   /** Convenient typdef for Feature data */
   typedef void* FeatureData;

   /**
      Convenient typedef for the feature handler function type.
      @param instance The plugin instance
      @param data Feature Data passed from host
    */
   typedef void(*FeatureHandler)(void* instance, void* data);

   /** Convenient typedef for the feature handler map type. */
   typedef map<string, FeatureHandler> FeatureHandlerMap;

   class FeatureIter
   {
   public:
       FeatureIter (const Feature* const* features)
           : m_index (0), p_feats (features) { }

       inline const Feature*
       next()
       {
           if (NULL == p_feats[m_index])
               return NULL;
           return p_feats[m_index++];
       }

   private:
       uint32_t                 m_index;
       const Feature* const*    p_feats;
   };
} /* namespace lvtk */

#endif /* LVTK_FEATURE_HPP */
