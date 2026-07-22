// Copyright (C) 2023 MapLibre contributors
// Copyright (C) 2019 Mapbox, Inc.

// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#include "types.hpp"

#include <mapbox/geojson.hpp>
#include <mbgl/util/feature.hpp>
#include <mbgl/util/geometry.hpp>

#include <QtCore/QVariant>

#include <string>

namespace QMapLibre::GeoJSON {

mbgl::Point<double> asPoint(const Coordinate &coordinate);
mbgl::MultiPoint<double> asMultiPoint(const Coordinates &multiPoint);
mbgl::LineString<double> asLineString(const Coordinates &lineString);
mbgl::MultiLineString<double> asMultiLineString(const CoordinatesCollection &multiLineString);
mbgl::Polygon<double> asPolygon(const CoordinatesCollection &polygon);
mbgl::MultiPolygon<double> asMultiPolygon(const CoordinatesCollections &multiPolygon);
mbgl::Value asPropertyValue(const QVariant &value);
mbgl::FeatureIdentifier asFeatureIdentifier(const QVariant &id);
mbgl::GeoJSONFeature asFeature(const Feature &feature);

// Reverse converters: mbgl::GeoJSONFeature -> QMapLibre::Feature.
// Only consumed by Map::queryRenderedFeatures.
CoordinatesCollections asCoordinatesCollections(const mbgl::Point<double> &point);
CoordinatesCollections asCoordinatesCollections(const mbgl::LineString<double> &lineString);
CoordinatesCollections asCoordinatesCollections(const mbgl::Polygon<double> &polygon);
CoordinatesCollections asCoordinatesCollections(const mbgl::MultiPoint<double> &points);
CoordinatesCollections asCoordinatesCollections(const mbgl::MultiLineString<double> &lineStrings);
CoordinatesCollections asCoordinatesCollections(const mbgl::MultiPolygon<double> &polygons);
QVariant asQVariant(const mbgl::Value &value);
QVariant asQVariant(const mbgl::FeatureIdentifier &id);
Feature asFeature(const mbgl::GeoJSONFeature &feature);

} // namespace QMapLibre::GeoJSON
