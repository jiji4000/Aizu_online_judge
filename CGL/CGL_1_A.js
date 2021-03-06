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
	v: Vector2D
*/
function rotateVector90(v){
	var r = new Vector2D();
	r.x = -v.y;
	r.y = v.x;
	return r;
}

/*
	get degree to radian
	return radian
*/
function getDegreeToRadian(degree){
	var pi = 3.14159265358979323846;
	return degree * pi / 180;
}

/*
	vec:Vector2D
	return Vector2D
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
 * line segment
 *
 * point1:Vector2D
 * point2:Vector2D
*/
var LineSegment2D = class LineSegment2D {
	constructor(point1,point2,color){
		this.point1 = point1;
		this.point2 = point2;
	}
}

LineSegment2D.prototype.Init = function(point1,point2,color){
	this.point1 = point1;
	this.point2 = point2;
}

/*
	Line Object
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
 * segment:segment
 * onto:Vector2D
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

	if(0 < d){
	    var dp = dotProduct2D(project,onto);
	    return multiplyVector(onto,dp / d);
	}
	return onto;
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

/**
	point class
*/
var Point2D = class Point2D {
	constructor(x,y,color){
		this.x = x;
		this.y = y;

	}
}

onload = function(){
	var fs = require('fs'); 
	//var input = require('fs').readFileSync('/dev/stdin', 'utf8');
	var input = require('fs').readFileSync('input.txt', 'utf8');
	var Arr=(input.trim()).split("\n");	
	var nums = Arr[0].split(" ").map(Number);
	// p1
	var p1 = new Vector2D(nums[0],nums[1]);
	var p2 = new Vector2D(nums[2],nums[3]);
	var projection = subtractVector(p1,p2);
	// 消す
	Arr.shift();
	Arr.shift();

	Arr.forEach(function(v){
	   var x = (v.split(" "))[0]-0;
	   var y = (v.split(" "))[0]-0;
	   var p = new Vector2D(x,y);
	   var projection2 = projectVector(projection,p);
	   console.log(projection2.x + " " + projection2.y + "\n");
	});	
};


