/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:22:41 by ekeinan           #+#    #+#             */
/*   Updated: 2025/06/28 22:05:16 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::string concepts[100] = {
		"Curiosity", "Patterns", "Memory", "Creativity", "Logic",
		"Decision", "Emotion", "Perception", "Attention", "Learning",
		"Problem", "Solution", "Imagination", "Focus", "Intuition",
		"Judgment", "Reflection", "Adaptation", "Innovation", "Reasoning",
		"Analysis", "Synthesis", "Prediction", "Observation", "Inspiration",
		"Motivation", "Doubt", "Certainty", "Confusion", "Clarity",
		"Association", "Connection", "Deduction", "Induction", "Abstraction",
		"Concentration", "Distraction", "Forgetting", "Remembrance", "Recall",
		"Recognition", "Concept", "Idea", "Insight", "Brainstorm",
		"Hypothesis", "Theory", "Evidence", "Belief", "Knowledge",
		"Wisdom", "Intelligence", "Understanding", "Comprehension", "Awareness",
		"Consciousness", "Subconscious", "Dream", "Reality", "Fantasy",
		"Vision", "Daydream", "Sensation", "Experience", "Illusion",
		"Hallucination", "Empathy", "Sympathy", "Apathy", "Ambition",
		"Desire", "Goal", "Purpose", "Meaning", "Challenge",
		"Obstacle", "Overcome", "Perseverance", "Success", "Failure",
		"Mistake", "Correction", "Growth", "Change", "Transformation",
		"Evolution", "Revolution", "Discovery", "Invention", "Design",
		"Creation", "Art", "Science", "Mathematics", "Language",
		"Communication", "Expression", "Interpretation", "Self-awareness", "Critical thinking"
	};
	
	for (size_t i = 0; i < 100; i++)
		concepts[i] = ideas[i];

	std::cout << "HI THIS IS BRAIN [0_0]" << std::endl;
}

Brain::Brain(const Brain &copied)
{
	std::cout <<
		"AYE AYE THIS BRAIN IS BEING COPIED [>_<]"
	<< std::endl;
	if (this != &copied)
		*this = copied;
}

Brain &Brain::operator=(const Brain &assigned)
{
	std::cout <<
		"AYE AYE THIS BRAIN IS BEING ASSIGNED [=_=]"
	<< std::endl;
	if (this != &assigned)
	{
		for (size_t i = 0; i < 100; i++)
			ideas[i] = assigned.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "BYE THIS IS BRAIN [v_v]" << std::endl;
}

