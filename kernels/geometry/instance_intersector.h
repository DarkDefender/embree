// ======================================================================== //
// Copyright 2009-2017 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "../common/scene_instance.h"
#include "../common/ray.h"

namespace embree
{
  namespace isa
  {
    struct FastInstanceIntersectorN
    {
      static void intersect1(const Instance* instance, const RTCIntersectContext* context, Ray& ray, size_t item);
      static void occluded1 (const Instance* instance, const RTCIntersectContext* context, Ray& ray, size_t item);

      template<int N>
      static void intersectN(vint<N>* valid, const Instance* instance, const RTCIntersectContext* context, RayK<N>& ray, size_t item);
      template<int N>
      static void occludedN (vint<N>* valid, const Instance* instance, const RTCIntersectContext* context, RayK<N>& ray, size_t item);
   
      static void intersect(int* valid, void* ptr, const RTCIntersectContext* context, RTCRayN* rays, size_t N, size_t item);
      static void occluded (int* valid, void* ptr, const RTCIntersectContext* context, RTCRayN* rays, size_t N, size_t item);
    };

    struct FastInstanceIntersector1M
    {
      static void intersect(const Instance* instance, RTCIntersectContext* context, Ray** rays, size_t M, size_t item);
      static void occluded (const Instance* instance, RTCIntersectContext* context, Ray** rays, size_t M, size_t item);
    };
  }
}