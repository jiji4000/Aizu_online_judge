// Vector2d
var Vector2D = class Vector2D {
	constructor(x,y){
		this.x = x;
		this.y = y;
	}
}

Vector2D.prototype.Init = function(x,y){
	this.x = x;
	this.y = y;
}

/*
 * v: Vector2D
 */
function rotateVector90(v){
	var r = new Vector2D();
	r.x = -v.y;
	r.y = v.x;
	return r;
}

/*
 * get degree to radian return radian
 */
function getDegreeToRadian(degree){
	var pi = 3.14159265358979323846;
	return degree * pi / 180;
}

/*
 * vec:Vector2D return Vector2D
 */
function getRotateVector(vec,degree){
	var radian = getDegreeToRadian(degree);

	var sin = Math.sin(radian);
	var cos = Math.cos(radian);

	var r = new Vector2D();
	r.x = vec.x * cos - vec.y * sin;
	r.y = vec.x * sin + vec.y * cos;

	return r;
}

function isEqualVectors(a,b){
	return equalFloats(a.x - b.x,0) && equalFloats(a.y - b.y,0);
}

/**
 * vec:Vector2D
 * 
 * return unitVector
 */
function getUnitVector(vec){
	var length = getVectorLength2D(vec);
	if(length > 0){
		return getDivideVector(vec,length);
	}
	return vec;
}

/**
 * return vector length
 * 
 * vec:Vector2D
 */
function getVectorLength2D(vec){
	return Math.sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

function getDivideVector(vec2D,length){
	vec2D.x = vec2D.x / length;
	vec2D.y = vec2D.y / length;
	return vec2D;
}

function equalFloats(a,b){
	var threshold = 1 / 8192;
	return Math.abs(a - b) < threshold;
}

function isParallelVector(vectorA,vectorB){
	var na = rotateVector90(vectorA);
	return equalFloats(0,dotProduct2D(na,vectorB));
}

function isVerticalVector(vectorA,vectorB){
	return equalFloats(0,dotProduct2D(vectorA,vectorB));
}

function subtractVector(vecA,vecB){
	var vec = new Vector2D();
	vec.x = vecA.x - vecB.x;
	vec.y = vecA.y - vecB.y;
	return vec;
}

function dotProduct2D(vecA,vecB){
	return vecA.x * vecB.x + vecA.y * vecB.y;
}

/**
 * 外積
 * 
 * @param vecA
 * @param vecB
 * @returns
 */
function getCloss(vecA,vecB){
	return vecA.x * vecB.y - vecA.y * vecB.x;;
}

/**
 * line segment
 * 
 * point1:Vector2D point2:Vector2D
 */
var LineSegment2D = class LineSegment2D {
	constructor(point1,point2){
		this.point1 = point1;
		this.point2 = point2;
	}
}

LineSegment2D.prototype.Init = function(point1,point2){
	this.point1 = point1;
	this.point2 = point2;
}

function onOneSide(axis,segment){
	var d1 = new Vector2D();
	d1 = subtractVector(segment.point1,axis.base);

	var d2 = new Vector2D();
	d2 = subtractVector(segment.point2,axis.base);

	var n = new Vector2D();
	n = rotateVector90(axis.direction);

	// 同じ方向だということを返す
	return dotProduct2D(n,d1) * dotProduct2D(n,d2) > 0;
}

function overLapping(minA,maxA,minB,maxB){
	return minB <= maxA && minA <= maxB;
}

function isSegmentsCollide(segment1,segment2){
	// 線分の方向をチェックするためのベクトル
	var axisA = new Line();
	var axisB = new Line();

	// 線分1のベクトルに対して、線分2が片側にあるかチェック
	axisA.base = segment1.point1;
	axisA.direction = subtractVector(segment1.point2,segment1.point1);

	if(onOneSide(axisA,segment2)){
		return false;
	}

	// 同じく
	axisB.base = segment2.point1;
	axisB.direction = subtractVector(segment2.point2,segment2.point1);

	if(onOneSide(axisB,segment1)){
		return false;
	}

	// 同じベクトルをもつケース
	if(isParallelVector(axisA.direction,axisB.direction)){
		var rangeA = getProjectSegment(segment1,axisA.direction);
		var rangeB = getProjectSegment(segment2,axisA.direction);

		// 重なっているか
		return isOverLappingRanges(rangeA,rangeB);
	}
	else{
		return true;
	}
}

/*
 * Line Object
 */
function Line(){
	// vector2D
	this.base;
	// vector2D
	this.direction
}

Line.prototype.Init = function(base,direction,color){
	this.base = base;
	this.direction = direction;
}

/**
 * Range
 */
var Range = class Range {
	constructor(min,max){
		this.min = min;
		this.max = max;
	}
}

function getMaxMinRange(range1,range2){
	var range = new Range();
	range.min = range1.min < range2.min ? range1.min : range2.min;
	range.max = range1.max < range2.max ? range2.max : range1.max;
	return range;
}

function getSortRange(range){
	var sorted = new Range(range.min,range.max);
	if(range.min > range.max){
		sorted.min = range.max;
		sorted.max = range.min;
	}
	return sorted;
}

function getNegateVector(vector){
	vector.x = -vector.x;
	vector.y = -vector.y;
	return vector;
}

function getAddVector(vecA,vecB){
	return new Vector2D(vecA.x + vecB.x,vecA.y + vecB.y);
}

/**
 * segment:segment onto:Vector2D
 * 
 * return Range
 */
function getProjectSegment(segment,onto){
	var ontoUnitVec = getUnitVector(onto);

	var range = new Range();
	range.min = dotProduct2D(ontoUnitVec,segment.point1);
	range.max = dotProduct2D(ontoUnitVec,segment.point2);

	range = getSortRange(range);
	return range;
}

function isOverLappingRanges(range1,range2){
	return overLapping(range1.min,range1.max,range2.min,range2.max);
}

function projectVector(project,onto){
	var d = dotProduct2D(onto,onto);
	console.log("d = " + d);

	if(0 < d){
	    var dp = dotProduct2D(project,onto);
	    console.log("dp = " + dp);
	    return multiplyVector(onto,dp / d);
	}
	return onto;
}

function getNorm(vec){
	return vec.x * vec.x + vec.y * vec.y;
}

/**
 * point class
 */
var Point2D = class Point2D {
	constructor(x,y){
		this.x = x;
		this.y = y;

	}
}

function addPoint(point1,point2){
	return new Point2D(point1.x + point2.x,point1.y + point2.y);
}

function subtractPoint(point1,point2){
	return new Point2D(point1.x - point2.x,point1.y - point2.y);
}

function multiplyPoint(point,scalar){
	return new Point2D(point.x * scalar,point.y * scalar);
}

/**
 * segment : LineSegment2D
 * point : Point
 */
function getProjectPoint(segment,point){
	var vec1 = new Vector2D(segment.point2.x - segment.point1.x,segment.point2.y - segment.point1.y);
	var vec2 = new Vector2D(point.x - segment.point1.x,point.y - segment.point1.y);
	var rate = dotProduct2D(vec2,vec1) / getNorm(vec1);
	var vec3 = multiplyVector(vec1,rate);
	var project = new Point2D(segment.point1.x + vec3.x,segment.point1.y + vec3.y);
	return project; 
}

function getReflectionPoint(segment,point){
	var projection = getProjectPoint(segment,point);
	// pから射影点までのベクトル
	var vec = subtractPoint(projection,point);
	// 2倍したものが射影点になる
	var refrectionPoint = multiplyPoint(vec,2);
	// 始点を足す
	return addPoint(refrectionPoint,point);
}

function multiplyVector(vec,scalar){
	var temp = new Vector2D();
	temp.x = vec.x * scalar;
	temp.y = vec.y * scalar;
	return temp;
}

function clampOnRange(x,min,max){
	if(x < min){
		return min;
	}else if(x > max){
		return max;
	}else{
		return x;
	}
}

var input = require('fs').readFileSync('/dev/stdin', 'utf8');
//var input = require('fs').readFileSync('input.txt', 'utf8');
var Arr=(input.trim()).split("\n");	
// 消す
Arr.shift();

Arr.forEach(function(v){
   var nums = v.split(" ").map(Number);
   var segment1 = new LineSegment2D(new Vector2D(nums[0],nums[1]),new Vector2D(nums[2],nums[3]));
   var segment2 = new LineSegment2D(new Vector2D(nums[4],nums[5]),new Vector2D(nums[6],nums[7])); 
   var ans = "0";
   if(isSegmentsCollide(segment1,segment2)){
	   ans = "1";
   }
   console.log(ans);
});