package com.truenorth.commands.dim;

import org.scijava.plugin.Parameter;

import net.imglib2.meta.Axes;
import net.imglib2.type.NativeType;
import net.imglib2.type.numeric.RealType;

/**
 * 
 * extend image by a specified number of voxels
 * 
 * @author bnorthan
 *
 * @param <T>
 */
public class ExtendCommandExtension<T extends RealType<T> & NativeType<T>> extends ExtendCommand<T> 
{
	@Parameter 
	int extensionXY;
	
	@Parameter
	int extensionZ;
	
	void CalculateExtendedDimensions()
	{
		System.out.println("Extend--Extension version!");
		
		int v=0;
		
		for(int d=0;d<input.numDimensions();d++)
		{ 	
						
			//if ( (input.axis(d).type()==Axes.X) || (input.axis(d).type()==Axes.Y))
			if ( (input.axis(d).type()==Axes.X) || (input.axis(d).type()==Axes.Y))
			{
				extendedDimensions[d]=input.dimension(d)+extensionXY*2;
				extendedVolumeDimensions[v]=input.dimension(d)+extensionXY*2;
				v++;
			}
			//else if ( (input.axis(d).type()==Axes.Z))
			else if ( (input.axis(d).type()==Axes.Z))
			{
				extendedDimensions[d]=input.dimension(d)+extensionZ*2;
				extendedVolumeDimensions[v]=input.dimension(d)+extensionZ*2;
				v++;
			}
			else
			{
				extendedDimensions[d]=input.dimension(d);
			}
		}
	}
	
}